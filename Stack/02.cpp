// Check for Balanced Parenthesis
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
    char data;
    Node *next;
};
Node *head = NULL;
void push(char ch){
    Node *newNode = new Node;
    newNode->data = ch;
    newNode->next = head;
    head = newNode;
}
char pop(){
    Node *temp = head;
    head = head->next;
    char item = temp->data;
    free(temp);
    return item;
}
int main(){
    string str;
    cout<<"Enter the String: ";
    getline(cin,str);
    int n = str.size();
    if(n%2!=0){
        cout<<"Unbalanced";
        exit(0);
    }
    string::iterator it;
    int countPush=0;
    int countPop=0;
    for(it=str.begin();it<str.end();it++){
        if(*it=='(' || *it=='{' || *it=='['){
            push(*it);
            countPush++;
        }
        else if(*it==')'){
            char popItem = pop();
            if(popItem!='('){
                cout<<"Unbalanced";
                exit(0);
            }
            else{
                countPop++;
                continue;
            }
        }
        else if(*it=='}'){
            char popItem = pop();
            if(popItem!='{'){
                cout<<"Unbalanced";
                exit(0);
            }
            else{
                countPop++;
                continue;
            }
        }
        else if(*it==']'){
            char popItem = pop();
            if(popItem!='['){
                cout<<"Unbalanced";
                exit(0);
            }
            else{
                countPop++;
                continue;
            }
        }
    }
    if(countPush==countPop)
        cout<<"Balanced";
    else
        cout<<"Unbalanced";
}