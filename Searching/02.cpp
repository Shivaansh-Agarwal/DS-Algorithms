// Binary Search
#include<iostream>
using namespace std;
int bsearch(int arr[], int l, int r, int x){
    if(r>=l){
        int mid = (l+r)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]<x)
            return bsearch(arr, mid+1, r, x);
        else if(arr[mid]>x)
            return bsearch(arr, l, mid-1, x);
    }
    return -1;
}
int main(){
    int n,x;
    int ans;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>x;
    ans = bsearch(arr,0,n-1,x);
    if(ans==-1)
        cout<<"Element not found";
    else
        cout<<"Element found at location "<<ans;
    return 0;
}