// singly Linked List Implementation
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;// next stores the address of type struct Node
};

struct Node *head = NULL;
struct Node *tail = NULL; // For insertion at the end

// Insertion at the beginning
void insert_at_beg(int elem){
    Node* new_node = new Node;
    new_node->data = elem;
    new_node->next = head;
    if(head==NULL && tail==NULL){
        tail = new_node;
    }
    head = new_node;
}

// Insertion at the end
// Since we've used the tail pointer, therefore the complexity is O(1)
void insert_at_end(int elem){
    // If user selects this choice, and the linked list is empty
    if(head==NULL){
        insert_at_beg(elem);
        return;
    }
    Node *new_node = new Node;
    new_node->data = elem;
    new_node->next = NULL;
    tail->next = new_node;
    tail = new_node;
}

void insert_in_btw(int prev,int elem){

}

void display(){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    struct Node* ptr;
    ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main(){
    int choice;
    while(true){
        cout<<"\n1. Insert element at beginning"<<endl;
        cout<<"2. Insert element at the end"<<endl;
        cout<<"3. Insert element in between"<<endl;
        cout<<"4. Remove first element"<<endl;
        cout<<"5. Remove last element"<<endl;
        cout<<"6. Remove element from between"<<endl;
        cout<<"7. Display elements"<<endl;
        cout<<"8. Quit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;
        if(choice==8)
            break;
        int elem,prev;
        switch(choice){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>elem;
                insert_at_beg(elem);
                break;
            case 2:
                cout<<"Enter the element to be inserted: ";
                cin>>elem;
                insert_at_end(elem);
                break;
            case 3:
                cout<<"Enter the element after which the new element is to be inserted: ";
                cin>>prev;
                cout<<"Enter the element to be inserted: ";
                cin>>elem;
                insert_in_btw(prev,elem);
                break;
            case 7:
                display();
                break;
        }
    }
    return 0;
}