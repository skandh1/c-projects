#include <iostream>

using namespace std;

class Queue
{
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    void enqueue(int value)
    {
        if (rear == MAX_SIZE - 1)
        {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        arr[++rear] = value;
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Underflow! Cannot dequeue from an empty queue." << endl;
            return;
        }
        cout << "Dequeued " << arr[front++] << " from the queue." << endl;
        if (front > rear)
        {
            front = rear = -1; // Reset front and rear if the last element is dequeued
        }
    }

    int peek() const
    {
        if (front == -1)
        {
            cerr << "Error: The queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() const
    {
        return front == -1;
    }

    void display() const
    {
        if (front == -1)
        {
            cout << "The queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i)
        {
            cout << arr[i] << " ";
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
