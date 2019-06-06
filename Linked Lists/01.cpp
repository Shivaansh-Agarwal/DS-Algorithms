// Linked List Implementation
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node *head = NULL;

void insert(int elem){
    Node* new_node = new Node;
    new_node->data = elem;
    new_node->next = head;
    head = new_node;
}

void display(){
    struct Node* ptr;
    ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main(){
    while(true){
        cout<<"\n1. Insert element at beginning"<<endl;
        cout<<"2. Delete element "<<endl;
        cout<<"3. Display the elments in the Linked List: "<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        cout<<endl;
        if(choice==4)
            break;
        int elem;
        switch(choice){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>elem;
                insert(elem);
                break;
            case 3:
                display();
                break;
        }
    }
    return 0;
}