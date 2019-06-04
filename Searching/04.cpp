// Given a Sorted Binary Array Count the number of 1's in it
/* 
    I/P:
        n = 12
        arr[] = {0,0,0,0,0,1,1,1,1,1,1,1}
    O/P:
        7
*/
/*
    ALGORITHM
    1. Using Modified Binary Search we'll find the index of first occurrence of 1 in the array
    2. Subtract that index from n, we'll get the required ans
*/
#include<iostream>
using namespace std;
int b_search_count_1(int arr[],int beg, int end){
    int mid = beg + (end-beg)/2;
    if(arr[mid]==1 && (mid==0 || arr[mid-1]!=1))
        return mid;
    else if(arr[mid]==0 && arr[mid+1]==1)
        return mid+1;
    else if(arr[mid]==0)
        return b_search_count_1(arr,mid+1,end);
    else if(arr[mid]==1 && arr[mid-1]==1)
        return b_search_count_1(arr,beg,mid-1);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(arr[n-1]==0)
        cout<<"No 1's are present in the Array";
    else{
        int ans = b_search_count_1(arr,0,n-1);
        cout<<n-ans;
    }
    return 0;
}