// Smallest Positive Missing Number
/*
    Given an array arr[] of size N, find the smallest missing interger from 1 to N in the array.
    If no integer is missing then answer is n+1.
*/
/*
    NOTE: Expected solution in O(n) time using constant extra space.
    I/P=>
        5               5
        1 2 3 4 5       0 -10 1 3 -20
    O/P=>
        6               2
*/
/*
    ALGORITHM
    1. Declare an array arr1[] of size n & initialize all elements by 0.
        This array is declared in order to store +ve elements in it.
    2. Iterate through the array arr[].
          i. If arr[i] is <= 0 ignore it.
         ii. If arr[i] > 0 AND arr[i]>n Ignore it.
        iii. If arr[i] > 0 AND arr[i]<n then arr1[arr[i]-1] = -1. // This will work as an indicator that YES we've that element in the array if it is marked as -1.
    3. Iterate through the array arr1[]
          i. If arr[i] > 0 THEN ans = i+1 AND break the loop
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],arr1[n]={};
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        if(arr[i]>0 && arr[i]<=n)
            arr1[arr[i]-1] = -1; 
    }
    int ans = n+1;
    for(int i=0;i<n;i++){
        if(arr1[i]==0){
            ans = i+1;
            break;
        }
    }
    cout<<"Missing Element: "<<ans;
    return 0;
}