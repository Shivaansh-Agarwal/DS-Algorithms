/*
Given an array A  which is sorted and contains N distinct elements. 
Also, this array is rotated at some unknown point. 
The task is to find the minimum element in it. 

Note: Expected time complexity is O(logN).
*/
/*
    I/P: n = 7
         arr[] = {2,3,4,5,6,7,1}
    O/P: 1

    I/P: n = 5
         arr[] = {4,5,6,2,3}
    O/P: 2

    I/P: n = 3
         arr[] = 20 162 462
    O/P: 20
*/
#include<iostream>
using namespace std;
int b_search_rotated_min(int arr[], int beg, int end, int n){
    int mid = beg + (end-beg)/2;
    if(beg>end)
        return -1;
    if(arr[mid]<arr[mid-1])
        return arr[mid];
    else if(mid!=n-1 && arr[mid]>arr[mid+1])
        return arr[mid+1];
    else if(arr[mid]<arr[beg])// we've to go left
        return b_search_rotated_min(arr, beg, mid-1, n);
    else if(arr[mid]>arr[beg])// we've to go right
        return b_search_rotated_min(arr, mid+1, end, n);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(arr[0]<arr[n-1])// if array is not rotated
        cout<<"Minimum element is: "<<arr[0];
    else{
        int ans = b_search_rotated_min(arr,0,n,n);
        cout<<"Minimum element is: "<<ans;
    }
    return 0;
}