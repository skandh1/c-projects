#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node *next;

        node(int val){
            data = val;
            next = NULL;
        }
};

void insertAtEnd(node* &tail, node* &head, int val){
        node *x = new node(val);

        if(tail == NULL){
            head = x;
            tail = x;
        }else{
        tail->next = x;
        tail = x;
        }
}

void insertAtFront(node* &tail, node* &head, int val){
        node *x = new node(val);

        if(tail == NULL && head == NULL){
            head = x;
            tail = x;
        }else{
        x->next = head;
        head = x;
        }
}


void display (node* head) {
        node *temp = head;
        while(temp!= NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout <<"NULL"<< endl;
}


int main(){
        node *head = NULL;
        node *tail = NULL;
        insertAtEnd(tail, head, 10);
        insertAtFront(tail, head, 20);
        insertAtEnd(tail, head, 30);
        insertAtFront(tail, head, 40);
        display(head);
        return 0;
}