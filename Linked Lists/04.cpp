// Reverse a Linked List (using Iteration)
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insert_at_beg(int elem){
    Node *new_node = new Node;
    new_node->data = elem;
    new_node->next = head;
    if(head==NULL)
        tail = new_node;
    head = new_node;
}

void insert_at_end(int elem){
    Node *new_node = new Node;
    new_node->data = elem;
    new_node->next = NULL;
    tail->next = new_node;
    tail = new_node;
}

void display(){
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void reverse_linked_list(){
    Node *curr = head;
    Node *temp = NULL;
    Node *prev = NULL;
    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

int main(){
    int elem;
    cout<<"Enter the element in the Linked List: ";
    cin>>elem;
    insert_at_beg(elem);
    char ch;
    while(true){
        cout<<"Do you want to enter another element (Y/N): ";
        cin>>ch;
        if(ch=='Y'){
            cout<<"Enter the element: ";
            cin>>elem;
            insert_at_end(elem);
        }
        else
            break;
    }
    cout<<"The elements in the linked list are: "<<endl;
    display();
    reverse_linked_list();
    cout<<"Reverse of Linked List: "<<endl;
    display();
}