// Tapping Rainwater (Naive Approach)
/*
    I/P => {2,0,2}
    O/P => 2

    I/P => {3,0,1,2,5}
    O/P => 6
*/
/*
    Time Complexity => O(n*n)
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int leftmax=arr[0],rightmax=arr[n-1];
    int ans=0;
    for(int i=1;i<n-1;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>leftmax)
                leftmax = arr[j];
        }
        for(int j=n-1;j>i;j--){
            if(arr[j]>rightmax)
                rightmax = arr[j];
        }
        ans = ans + min(leftmax,rightmax) - arr[i];
    }
    cout<<ans;
}
