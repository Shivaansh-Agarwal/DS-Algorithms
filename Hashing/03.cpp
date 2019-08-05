/*
    PROBLEM STATEMENT
    Given an array find if there is a subarray with 0 sum.
    I/P: arr[] = {5,6,-4,-2,8,10}
    O/P: true

    I/P: arr[] = {5,6,-2,3}
    O/P: false

    I/P: arr[] = {5,-5,10}
    O/P: true
*/
// Optimal Solution using Hashing O(n)
#include<iostream>
#include<unordered_set>
using namespace std;
bool ifZeroSumArray(int arr[], int n){
    int preSum = 0;
    bool ans = false;
    unordered_set<int> us;
    us.insert(0);
    for(int i=0;i<n;i++){
        preSum += arr[i];
        // if element is not found find() returns iterator to the last element of the array
        if(us.find(preSum)!=us.end()){
            // if element is found
            ans = true;
        }
        us.insert(preSum);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bool ans = ifZeroSumArray(arr,n);
    if(ans)
        cout<<"YES there is a subarray with 0 Sum in the Array";
    else
        cout<<"NO there is no subarray with 0 Sum in the Array";
    return 0;
}