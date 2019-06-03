// Given a Sorted Array, Find the number of occurrences of a given number
/*
    1. O(n) [Linear Search]
    2. O(number_of_occurrences)
    3. O(log n)
*/
/*
    n = 5
    arr[] = 2,5,5,5,6
    O/P=> 3
*/
#include<iostream>
using namespace std;

int b_search_first(int arr[], int beg, int end, int x){
    int mid = beg + (end-beg)/2;
    if(beg>end)
        return -1;
    if(arr[mid]==x){
        if(mid==0 || arr[mid-1]!=x)
            return mid;
        else
            return b_search_first(arr,beg,mid-1,x);
    }
    else if(arr[mid]>x)
        return b_search_first(arr, beg, mid-1, x);
    else if(arr[mid]<x)
        return b_search_first(arr, mid+1, end, x);
}
int b_search_last(int arr[], int beg, int end, int x, int n){
    int mid = beg + (end-beg)/2;
    if(beg>end)
        return -1;
    if(arr[mid]==x){
        if(mid==n-1 || arr[mid+1]!=x)
            return mid;
        else
            return b_search_last(arr,mid+1,end,x,n);
    }
    else if(arr[mid]>x)
        return b_search_last(arr, beg, mid-1, x, n);
    else if(arr[mid]<x)
        return b_search_last(arr, mid+1, end, x, n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;
    int first, last;
    first = b_search_first(arr,0,n-1,x);
    last = b_search_last(arr,0,n-1,x,n);
    //cout<<first<<last<<endl;
    int ans = last - first + 1;
    cout<<ans;
    return 0;
}