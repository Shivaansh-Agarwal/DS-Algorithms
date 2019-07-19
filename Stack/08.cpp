// "Next Greater Element" OR "Nearest Greater Element on Right Side"
/*
    PROBLEM STATEMENT
    Given an array, print the Next Greater Element (NGE) for every element. 
    The Next greater Element for an element x is the first greater element on the right side of x in array. 
    Elements for which no greater element exist, consider next greater element as -1.

    Example:
    I/P: arr[] = {5,10,7,8,3,2,12}
    O/P: ans[] = {10,12,8,12,12,12,-1}
*/
/*
    APPROACH-1 (Naive Approach) O(n^2)
    nextGreatest[n] = {-1};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                nextGreatest[i] = arr[j];
                break;
            }
        }
    }

    APPROACH-2 (Efficient Approach) O(n) => Using Stack
    This approach has been used here.
    The logic is simlar to the Stock Span Problem.
*/
#include<iostream>
#include<stack>
using namespace std;

void printNextGreatestElement(int ans[],int n){
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
}

void NextGreatest(int arr[], int n){
    stack <int> s;
    s.push(0);
    int ans[n] = {-1};
    for(int i=1;i<n;i++){
        /* 
            Whenever the next element in the array, arr[i] is greater than Top element in the stack, arr[s.top()]
            We keep popping the elements until the elements are less than arr[i]
            
            Finally every element is pushed in the stack
        */
        while(!s.empty() && arr[s.top()]<arr[i]){
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    ans[n-1] = -1;
    printNextGreatestElement(ans,n);
}

int main(){
    int arr[] = {5,10,7,8,3,2,12};
    int n = sizeof(arr)/sizeof(int);
    NextGreatest(arr,n);
    return 0;
}
