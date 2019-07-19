// Previous Greater Element
/*
    PROBLEM STATEMENT
    Given an array, print the previous greater element of each element in the array.

    Example:
    I/P: arr[] = {45,23,41,12,24,42,5,2,50,17};
    O/P: ans[] = {-1,45,45,41,41,45,42,5,-1,50};
*/
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
void print(int* prevGreaterArray,int n){
    for(int i=0;i<n;i++)
        cout<<prevGreaterArray[i]<<" ";
    cout<<endl;
}
int* prevGreater(int arr[], int n){
    stack<int> s;
    s.push(n-1);
    int *prevGreaterArray = new int[n];
    // Using this function we can assign a default value to an array
    std::fill_n(prevGreaterArray, n, -1); // #include<algorithm>
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && arr[s.top()]<arr[i]){
            prevGreaterArray[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    //prevGreaterArray[0] = -1;
    return prevGreaterArray;
}
int main(){
    int arr[] = {45,23,41,12,24,42,5,2,50,17};
    int n = sizeof(arr)/sizeof(int);
    int *prevGreaterArray = prevGreater(arr,n);
    print(prevGreaterArray,n);
    return(0);
}