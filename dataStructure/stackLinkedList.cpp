#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from the stack." << endl;
        delete temp;
    }

    int peek() const
    {
        if (top == nullptr)
        {
            cerr << "Error: The stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    void display() const
    {
        if (top == nullptr)
        {
            cout << "The stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        Node *current = top;
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
    Stack myStack;
    int choice, value;

    do
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Display Stack\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push onto the stack: ";
            cin >> value;
            myStack.push(value);
            break;

        case 2:
            myStack.pop();
            break;

        case 3:
            value = myStack.peek();
            if (value != -1)
            {
                cout << "Top element: " << value << endl;
            }
            break;

        case 4:
            cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
            break;

        case 5:
            myStack.display();
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
