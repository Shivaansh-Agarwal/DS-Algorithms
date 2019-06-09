//Given a Linked List find the MIDDLE ELEMENT of it using only 1 traversal.
/*
    So 1st approach is solving using 2 traversals
    In the first traversal we calculate the length of the linked list.
    In the second traversal we find the n/2th element.

    In the 2nd Approach, we'll use only 1 traversal but 2 pointers.
    One Pointer will move at the double speed, so when that pointer reaches last element, the slow pointer will reach the middle element.
*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

// Node *head = NULL;
struct Node *head = NULL;

Node *tail = NULL;
//struct Node *tail = NULL;

void insert_at_beg(int elem){
    Node *new_node = new Node;
    new_node->data = elem;
    new_node->next = NULL;
    head = new_node;
    tail = new_node;
}

void insert_at_end(int elem){
    Node *new_node = new Node;
    new_node->data = elem;
    new_node->next = NULL;
    tail->next = new_node;
    tail = new_node;
}

void find_middle(){
    if(head==NULL)
        cout<<"Linked List is Empty";
    else if(head->next==NULL)// If there is only 1 element
        cout<<head->data;
    else{
        Node *slow = new Node;
        Node *fast = new Node;
        slow = head;
        fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            cout<<slow->data<<" ";
        }
        cout<<"Middle Element is: "<<slow->data;
    }
}

void display(){
    Node *ptr = new Node;
    ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
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
    display();
    find_middle();
    return 0;
}