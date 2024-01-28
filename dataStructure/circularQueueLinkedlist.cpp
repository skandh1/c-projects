#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue
{
private:
    Node *front;
    Node *rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
            rear->next = front; // Point rear's next to front to make the queue circular
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Point rear's next to front to maintain circularity
        }
        cout << "Enqueued " << value << " into the circular queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Cannot dequeue from an empty circular queue." << endl;
            return;
        }
        Node *temp = front;
        if (front == rear)
        {
            front = rear = nullptr; // Reset front and rear if the last element is dequeued
        }
        else
        {
            front = front->next;
            rear->next = front; // Update rear's next to maintain circularity
        }
        cout << "Dequeued " << temp->data << " from the circular queue." << endl;
        delete temp;
    }

    int peek() const
    {
        if (isEmpty())
        {
            cerr << "Error: The circular queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() const
    {
        return front == nullptr && rear == nullptr;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "The circular queue is empty." << endl;
            return;
        }

        cout << "Circular Queue elements: ";
        Node *current = front;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

int main()
{
    CircularQueue myCircularQueue;
    int choice, value;

    do
    {
        cout << "\nCircular Queue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Circular Queue is Empty\n";
        cout << "5. Display Circular Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to enqueue into the circular queue: ";
            cin >> value;
            myCircularQueue.enqueue(value);
            break;

        case 2:
            myCircularQueue.dequeue();
            break;

        case 3:
            value = myCircularQueue.peek();
            if (value != -1)
            {
                cout << "Front element: " << value << endl;
            }
            break;

        case 4:
            cout << "Is the circular queue empty? " << (myCircularQueue.isEmpty() ? "Yes" : "No") << endl;
            break;

        case 5:
            myCircularQueue.display();
            break;

        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}
