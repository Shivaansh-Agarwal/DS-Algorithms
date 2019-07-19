// Next Smaller Element
/*
    PROBLEM STATEMENT
    Given an array find the next smaller element of every element in the array

    I/P: arr[] = {43,12,33,78,32,5,1,67}
    O/P: ans[] = {12,5,32,32,5,1,,-1,-1}
*/
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

void print(int *nextSmallerArray, int n){
    for(int i=0;i<n;i++)
        cout<<nextSmallerArray[i]<<" ";
}
int* nextSmaller(int arr[], int n){
    stack<int> s;
    /*
        All the elements will be pushed into the stack.
        BUT at any point in time only those elements will be present in the stack whose NEXT SMALLER element hasn't been found.
        Whenever we find the nextSmaller for any element that element will be popped from the Stack.
    */
    s.push(0);
    int *nextSmallerArray = new int[n]; //Dynamic Array Allocation since I've to return this array from this function.
    std::fill_n(nextSmallerArray,n,-1); // By default all elements of the 'nextSmallerArray' will store -1.
    for(int i=1;i<n;i++){
        // This loop will iterate through all the elements of the Array starting from 1st index
        while(!s.empty() && arr[s.top()]>arr[i]){
            /*
                Here this while loop will run until, when is stack is not Empty, AND
                an element is found in the array which is smaller than the top element of the Stack.
            */
            nextSmallerArray[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return nextSmallerArray;
}
int main(){
    int arr[] = {43,12,33,78,32,5,1,67};
    int n = sizeof(arr)/sizeof(int);
    int *nextSmallerArray = nextSmaller(arr,n);
    print(nextSmallerArray,n);
    return 0;
}