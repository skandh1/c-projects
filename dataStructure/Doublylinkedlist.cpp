#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        prev = NULL;
        data = val;
        next = NULL;
    }
};

class linkedlist
{
    node *head = NULL;
    node *tail = NULL;

public:
    void insertAtEnd(int val)
    {
        node *x = new node(val);
        if (head == NULL)
        {
            head = x;
            tail = x;
        }
        else
        {
            tail->next = x;
            x->prev = tail;
            tail = x;
        }
        cout << "value inserted \n\n";
    }
    void insertAtFront(int val)
    {
        node *x = new node(val);

        if (tail == NULL && head == NULL)
        {
            head = x;
            tail = x;
        }
        else
        {

            x->next = head;
            head->prev = x;
            head = x;
        }
        cout << "value inserted \n\n";
    };
    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "kuch nahi hai bhai\n\n";
        }
        else if (head->next == NULL)
        {
            head = nullptr;
            tail = nullptr;
            cout << "value deleted";
        }
        else
        {
            node *temp = head;
            while (head->next->next != NULL)
            {
                head = head->next;
            }
            head->next = NULL;
            head = temp;
            cout << "value deleted";
        }
    }
    void deleteFront()
    {
        if (head == NULL)
        {
            cout << "kuch nahi hai bhai\n\n";
        }
        else if (head->next == NULL)
        {
            head = nullptr;
            tail = nullptr;
            cout << "value deleted";
        }
        else
        {
            head = head->next;
            cout << "value deleted";
        }
    }
    int insertAFter(int key, int val)
    {
        node *x = new node(val);
        if (head == NULL)
        {
            cout << "empty list";
        }
        else if (head->data == key)
        {
            insertAtEnd(val);
        }
        else
        {
            node *temp = head;
            while (head->data != key)
            {
                if (head->next == NULL)
                {
                    cout << "no value found reinter value";
                    head = temp;
                    return 0;
                }
                head = head->next;
            }
            x->next = head->next;
            head->next = x;
            x->prev = head;
            head->next->prev = x;
            cout << "value inserted\n\n";
            head = temp;
            return 0;
        }
    }
    int insertBefore(int key, int val)
    {
        node *x = new node(val);
        if (head == NULL)
        {
            cout << "empty list";
        }
        else if (head->data == key)
        {
            insertAtFront(val);
            cout << "value inserted\n\n";
        }
        else
        {
            node *temp = head;
            while (head->next->data != key)
            {
                head = head->next;
                if (head->next == NULL)
                {
                    cout << "no value found reinter value";
                    head = temp;
                    return 0;
                }
            }
            x->prev = head;
            x->next = head->next;
            head->next = x;
            cout << "value inserted\n\n";
            head = temp;
            return 0;
        }
    }
    void deleteValue(int val)
    {
        node *temp = head;
        if (head->data == val)
        {
            deleteFront();
            return;
        }
        while (head->next != NULL)
        {
            if (head->next->data == val)
            {
                head->next->next->prev = head;
                head->next = head->next->next;
                head = temp;

                cout << "Value deleted \n\n";
                return;
            }
            head = head->next;
        }
        head = temp;
        cout << "value not found \n\n";
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "\n\n kuch nahi hai bhai isme \n\n";
            return;
        }
        else
        {
            cout << "NULL";
            node *temp = head;
            while (temp != NULL)
            {
                cout << "<-" << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }
    }
};

int main()
{
    linkedlist list;

    for (int i = 0; i < 10; i++)
    {
        list.insertAtFront(rand() / 100);
    }
    int n, key, number;

    do
    {
        cout << "\n\nChoose an option:\n\n";
        cout << "1. Enter the value at the end of list\n\n";
        cout << "2. Enter at the front fo the list\n\n";
        cout << "3. Display the list\n\n";
        cout << "4. delete from end: \n\n";
        cout << "5. Delete from front \n\n";
        cout << "6. Insert after \n\n";
        cout << "7. insert before \n\n";
        cout << "8  delete a specific value \n\n";
        cout << "9. exit \n\n ";

        cin >> n;

        switch (n)
        {
        case 1:
            cout << "put the number you want to insert \n\n";
            cin >> number;
            list.insertAtEnd(number);
            break;
        case 2:
            cout << "put the number you want to insert \n\n";
            cin >> number;
            list.insertAtFront(number);
            break;
        case 3:
            list.display();
            break;
        case 4:
            list.deleteEnd();
            break;
        case 5:
            list.deleteFront();
            break;
        case 6:
            cout << "choose the number after which you have to put value: \n\n";
            cin >> key;
            cout << "choose the value that you want to insert \n\n";
            cin >> number;
            list.insertAFter(key, number);
            break;
        case 7:
            cout << "choose the number before which you have to put value: \n\n";
            cin >> key;
            cout << "choose the value that you want to insert\n\n";
            cin >> number;
            list.insertBefore(key, number);
            break;
        case 8:
            cout << "choose the value you want to delete\n\n";
            cin >> number;
            list.deleteValue(number);
            break;
        case 9:
            cout << "see you soon\n\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n\n";
        }
    } while (n != 9);

    return 0;
}