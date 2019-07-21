// Print minimum of stack at every Pop
/*
    PROBLEM STATEMENT
    Given an array of Integers, Push them into the stack, then at every pop print the minimum element of the Stack.

    I/P: 1 2 3 4 5
    O/P: 1 1 1 1 1

    I/P: 1 6 43 1 2 0 5
    O/P: 0 0 1 1 1 1 1
*/
#include<iostream>
#include<stack>
using namespace std;
stack<int>_push(int arr[],int n){
   stack<int> s;
   int min = arr[0];
   s.push(min);
   for(int i=1;i<n;i++){
        if(min>arr[i])
            min = arr[i];
        s.push(min);
   }
   return s;
}
void _getMinAtPop(stack<int>s)
{
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    stack<int> s = _push(arr,n);
    _getMinAtPop(s);
    cout<<endl;
}