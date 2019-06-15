// Find the k-th element from the End of a Linked List
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insert_at_beg(int elem){
    Node *new_node = new Node;
    new_node->data = elem;
    new_node->next = head;
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
    cout<<"The elements in the linked list are: "<<endl;
    display();
    
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    Node *ptr = head;
    int i=0;
    while(i<k){
        ptr = ptr->next;
        i++;
    }
    Node *ptr1 = head;
    while(ptr!=NULL){
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    cout<<k<<"th element form end is: "<<ptr1->data;
    return 0;
}