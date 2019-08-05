/*
    PROBLEM STATEMENT
    Given an array find if there is a subarray with 0 sum.
    I/P: arr[] = {5,6,-4,-2,8,10}
    O/P: true

    I/P: arr[] = {5,6,-2,3}
    O/P: false
*/
// Naive Solution O(n^2)
#include<iostream>
using namespace std;
void ifZeroSumArray(int *arr, int n){
    int sum,ans=false;
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=i;j<n;j++){
           sum += arr[j];
           if(sum==0){
               cout<<"YES this array has subarray starting from index: "<<i<<" till index "<<j<<" whose sum is 0.";
               ans = true;
               break;
           }
        }
        if(ans)
            break;
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ifZeroSumArray(arr,n);
    return 0;
}