// Queue Implementation using a Linked List
#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
// Insertion from tail & Deletion from head

void enqueue(int elem){
    Node *newNode = new Node;
    newNode->data = elem;
    newNode->next = NULL;
    // If Queue is empty
    if(tail==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void dequeue(){
    
    Node *temp = head;
    //If there is no element in the queue
    if(head==tail && head==NULL){
        cout<<"No element is present in the queue"<<endl;
        return;
    }
    // Condition when IF there is only 1 element
    cout<<"Element Dequeued is: "<<temp->data<<endl;
    if(head==tail){
        tail = NULL;
        head = NULL;
        free(temp);
    }
    else{
        head = head->next;
        free(temp);
    }
}

void front(){
    // front is where from which Elements are Dequeued
    cout<<"Front Element: "<<head->data<<endl;
}

void rear(){
    // rear is where from which Element are Inserted
    cout<<"Rear Element: "<<tail->data<<endl;
}

int main(){
    int choice,elem;
    while(true){
        cout<<"1. Enqueue";
        cout<<"\n2. Dequeue";
        cout<<"\n3. Front Element";
        cout<<"\n4. Rear Element";
        cout<<"\n5. Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>elem;
                enqueue(elem);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                front();
                break;
            case 4:
                rear();
                break;
            case 5:
                exit(0);
        }
    }
}