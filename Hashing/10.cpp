/* 
    PROBLEM STATEMENT:
    Given a binary array find length of the largest subarray having equal number of 0's and 1's

    I/P: arr[] = {0,1,1,0,1,1,0}
    O/P: 4

    I/P: arr[] = {1,1,1,1}
    O/P: 0

    I/P: arr[] = {1,1,1,1,0,0,1,1,1,1,0,0}
    O/P: 8
*/
#include<iostream>
#include<unordered_map>
using namespace std;
int findLength(int *arr,int n){
    
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans = findLength(arr,n);
    cout<<"Length of largest subarray having equal number of 0's and 1's is: "<<ans;
    return 0;
}