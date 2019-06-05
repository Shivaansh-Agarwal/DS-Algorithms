/*
    Given an array of N+2 integer elements. 
    All elements of the array are in range 1 to N. 
    And all elements occur once except two numbers which occur twice. 
    Find the two repeating numbers.
*/
/*
    I/P: n = 4
         arr[] = 1 2 1 3 4 3

    O/P: 1 3
*/
#include<iostream>
using namespace std;

void twoRepeated(int arr[], int n){
    // Your code here
    int arr2[n+1] = {};
    for(int i=0;i<n+2;i++){
        if(arr2[arr[i]]==0){
            arr2[arr[i]]+=1;
            continue;
        }
        else if(arr2[arr[i]]!=0){
            cout<<arr[i]<<" ";
            continue;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=0;i<n+2;i++)
        cin>>arr[i];
    twoRepeated(arr,n);
    return 0;
}