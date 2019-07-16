// Print Reverse of a Linked List (Using Stack)
/*
    There are 3 ways to Reverse a Linked List-
    1. Iteration
    2. Recursion
    3. Using Stacks (Implemented Here)
 */
/*
    Ex:
    Consider the following Linked List
    head -> 24 -> 56 -> 54 -> 11 -> 90 -> X
 */
#include<iostream>
#include<stack>

using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head = NULL;

int main(){
    Node *one = new Node;
    Node *two = new Node;
    Node *three = new Node;
    Node *four = new Node;
    Node *five = new Node;
    head = one;
    one -> data = 24;
    two -> data = 56;
    three -> data = 54;
    four -> data = 11;
    five -> data = 90;
    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = NULL;

    stack<int> s1;

    Node *temp = head;
    while(temp!=NULL){
        s1.push(temp->data);
        temp = temp->next;
    }
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }

    return 0;
}