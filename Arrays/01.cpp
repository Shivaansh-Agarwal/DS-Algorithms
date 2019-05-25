// Reverse an Array
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int temp;
    for(int i=0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    cout<<"Array after being reversed is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}