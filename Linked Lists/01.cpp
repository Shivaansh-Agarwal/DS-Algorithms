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
    Node *ptr = head;
    while(ptr!=NULL){
        if(ptr->data==prev){
            Node *new_node = new Node;
        }
    }
}

void remove_from_beg(){
    head = head->next; 
}

void remove_from_end(){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
    }
    else if(head->next==NULL){
        remove_from_beg();
    }
    else{
        Node *ptr = head;
        while(ptr->next->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = NULL;
        tail = ptr;
    }
}

void remove_from_between(int elem){
    Node *ptr = head;
    while(ptr->next!=NULL){
        if(ptr->next->data==elem){
            ptr->next = ptr->next->next;
            break;
        }
    }
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
    cout<<endl;
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
            case 4:
                if(head==NULL){
                    cout<<"Linked List is empty"<<endl;
                }
                else{
                    remove_from_beg();
                    cout<<"First Element removed"<<endl;
                }
                break;
            case 5:
                if(head==NULL){
                    cout<<"Linked List is Empty"<<endl;
                }
                else{
                    remove_from_end();
                    cout<<"Last element removed"<<endl;
                }
                break;
            case 6:
                if(head==NULL){
                    cout<<"Linked List is Empty"<<endl;
                }
                else{
                    cout<<"Enter the element to be removed: ";
                    cin>>elem;
                    if(head->data==elem){
                        remove_from_beg();
                    }
                    else if(tail->data==elem){
                        remove_from_end();
                    }
                    else
                        remove_from_between(elem);
                }
                break;
            case 7:
                display();
                break;
        }
    }
    return 0;
}