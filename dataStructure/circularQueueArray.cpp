#include <iostream>

using namespace std;

class CircularQueue
{
private:
    static const int MAX_SIZE = 5; // Assuming a fixed size for the circular queue
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    void enqueue(int value)
    {
        if ((rear + 1) % MAX_SIZE == front)
        {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
        cout << "Enqueued " << value << " into the circular queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Cannot dequeue from an empty circular queue." << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << " from the circular queue." << endl;
        if (front == rear)
        {
            front = rear = -1; // Reset front and rear if the last element is dequeued
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int peek() const
    {
        if (isEmpty())
        {
            cerr << "Error: The circular queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() const
    {
        return front == -1 && rear == -1;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "The circular queue is empty." << endl;
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
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
