// Stack Implementation using Linked List
/*
    1. Implement a Linked List
    2. Use it to create a Stack Data Structure
*/
#include<iostream>
#include<cstdlib> // This library has been used to implement the 'free()' function which is used to deallocate previously allocated memory.
//#include<cstdio>
using namespace std;
struct Node{
    int data;
    Node *next;
};
Node *head = NULL;
void push(int num){
    Node *newNode = new Node;
    newNode->data = num;
    if(head==NULL){
        head = newNode;
        newNode->next = NULL;
        cout<<"First Element Pushed";
    }
    else{
        Node *temp = head;
        head = newNode;
        newNode->next = temp;
        cout<<"Element Pushed";
    }
}
void pop(){
    if(head==NULL){
        cout<<"Underflow";
        return;
    }
    else{
        int num = head->data;
        Node *temp = head;
        head = head->next;
        free(temp);
        cout<<"Popped Element is: "<<num<<endl;
    }
}
void top(){
    if(head==NULL){
        cout<<"Stack is Empty";
        return;
    }
    else{
        cout<<"TOP Element: "<<head->data<<endl;
    }
}
bool isEmpty(){
    if(head==NULL)
        return true;
    else
        return false;
}
int main(){
    int choice;
    int num;
    while(true){
        cout<<"1. Push Element"<<endl;
        cout<<"2. Pop Element"<<endl;
        cout<<"3. Get top element"<<endl;
        cout<<"4. isEmpty"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>num;
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                cout<<isEmpty();
                break;
            case 5:
                exit(0);
        }
    }
}