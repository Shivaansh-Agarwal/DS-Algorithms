// Leaders in an Array (Efficient Method)
/*
    arr[] = {5,3,20,15,8,3}
    Leaders = 20 15 8 3

    arr[] = {5,3,20,15,8,25,3}
    Leaders = 25 3
*/
/*
    Time Complexity => O(n)
*/
/*
    Here we iterate the array from the end & see
    if that element is the largest until that point from the end.
    BUT in this method the elements will be printed in the reverse order.
    So we can use a Stack and then print the elements.
*/
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int max = arr[n-1];

    stack<int> s;
    //cout<<max<<" ";
    s.push(max);
    
    for(int i=n-2;i>=0;i--){
        if(max<arr[i]){
            max = arr[i];
            //cout<<max<<" ";
            s.push(max);
        }
    }

    // Printing elements in the stack
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}