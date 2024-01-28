#include <iostream>

using namespace std;

class Stack
{
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(int value)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack Overflow! Cannot push element " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack." << endl;
    }

    int peek() const
    {
        if (top == -1)
        {
            cerr << "Error: The stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    void display() const
    {
        if (top == -1)
        {
            cout << "The stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << arr[i] << " ";
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
