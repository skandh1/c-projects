#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue Underflow! Cannot dequeue from an empty queue." << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr; // Reset rear if the last element is dequeued
        }
        cout << "Dequeued " << temp->data << " from the queue." << endl;
        delete temp;
    }

    int peek() const
    {
        if (front == nullptr)
        {
            cerr << "Error: The queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void display() const
    {
        if (front == nullptr)
        {
            cout << "The queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue myQueue;
    int choice, value;

    do
    {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Display Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to enqueue into the queue: ";
            cin >> value;
            myQueue.enqueue(value);
            break;

        case 2:
            myQueue.dequeue();
            break;

        case 3:
            value = myQueue.peek();
            if (value != -1)
            {
                cout << "Front element: " << value << endl;
            }
            break;

        case 4:
            cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
            break;

        case 5:
            myQueue.display();
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
