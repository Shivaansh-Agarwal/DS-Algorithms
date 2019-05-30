// Equilibrium Point
/*
    Given an Array arr[] of n elements. The task is to find the position of an element 
    of which sum of elements on LHS is equal to sum of elements on RHS.
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0; // This will contain the sum of all elements of the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum = sum + arr[i];
    }
    int leftsum = 0; // This will be used for storing the sum of elements on LHS of a number
    int ans;  // This will be used for storing the position of required element.
    for(int i=0;i<n;i++){
        sum = sum - arr[i]; // This determines the sum of elements on RHS of arr[i];
        if(leftsum == sum){
            ans = i + 1;
            break;
        }
        leftsum = leftsum + arr[i]; // This calculates the sum of elements on LHS of arr[i+1] for next iteration
    }
    cout<<ans;
    return 0;
}