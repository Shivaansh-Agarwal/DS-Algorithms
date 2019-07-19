// Previous Smaller Element
/*
    PROBLEM STATEMENT
    Given an array, determine the previous smaller element for every element in the array.

    I/P: arr[] = {21,34,12,5,67,33,90,7,2};
    O/P: ans[] = {-1,21,-1,-1,5,5,33,5,-1};
*/
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void print(int* prevSmallerArray, int n){
    for(int i=0;i<n;i++)
        cout<<prevSmallerArray[i]<<" ";
    cout<<endl;
}
int *prevSmaller(int arr[], int n){
    stack<int> s;
    /*
        All elements will be pushed in the Stack,
        But at any point of time only those elements will remain in the stack whose,
        previous smaller element hasn't been found.
        Whenever an element is found in the array which is smaller than the Top-Most element of the Stack,
        We'll pop that element.
    */
    // Since we've to find the previous Smaller element, so I've pushed the index of last element of the array
    s.push(n-1);
    int *prevSmallerArray = new int[n];
    // #include<algorithm> is used for below line of code.
    std::fill_n(prevSmallerArray,n,-1); // Assigning every element of the array by -1 initially.
    for(int i=n-2;i>=0;i--){
        /*  
            Since we need to find the Previous Smaller Element,
            I've iterated the loop from the end,
            and then used the same logic as I would've used in the 
            Next Smaller Element.
        */
        while(!s.empty() && arr[s.top()]>arr[i]){
            // We'll start popping the elements from the stack when we find the element which is less than it.
            prevSmallerArray[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return prevSmallerArray;
}
int main(){
    int arr[] = {21,34,12,5,67,33,90,7,2};
    int n = sizeof(arr)/sizeof(int);
    int *prevSmallerArray = prevSmaller(arr,n);
    print(prevSmallerArray,n);
    return 0;
}