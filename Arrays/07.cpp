// Tapping Rainwater (Efficient Approach)
/*
    I/P => {2,0,2}
    O/P => 2

    I/P => {3,0,1,2,5}
    O/P => 6
*/
/*
    Time Complexity => O(n)
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
    int leftmax[n], rightmax[n];
    leftmax[0] = 0;
    rightmax[n-1] = 0;
    int max = arr[0];
    for(int i=1;i<n;i++){
        leftmax[i] = max;
        if(arr[i]>max)
            max = arr[i];
    }
    max = arr[n-1];
    for(int i=n-2;i>=0;i--){
        rightmax[i] = max;
        if(arr[i]>max)
            max = arr[i];
    }
    int ans = 0;
    for(int i=1;i<n-1;i++){
        ans += min(leftmax[i],rightmax[i]) - arr[i];
    }
    cout<<ans;
    return 0;
}