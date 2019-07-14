// Stack Implementation using C++ STL
// The C++ STL offers a built-in class named stack for implementing the stack data structure easily and efficiently.
// This class provides almost all functions needed to perform the standard stack operations like push(), pop(), peek(), remove() etc..
// stack< data_type > stack_name;

#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> s1;
    cout<<"Size of the Stack is: "<<s1.size()<<endl;
    cout<<"Is the stack Empty: "<<s1.empty()<<endl;
    s1.push(20);
    s1.push(25);
    s1.push(45);
    s1.push(76);
    cout<<"Size of the Stack after pushing elements is: "<<s1.size()<<endl;
    cout<<"Is the stack Empty: "<<s1.empty()<<endl;
    cout<<"The topmost element of the stack is: "<<s1.top()<<endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<"Size of the Stack after Popping elements is: "<<s1.size()<<endl;
    cout<<"Is the stack Empty: "<<s1.empty()<<endl;
    return 0;
}