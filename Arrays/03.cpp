// Rotating an Array (using Reverse OPeration 3 times)
#include<iostream>
using namespace std;
void reverse(int *arr, int s, int n){
    int temp;
    int c;
    for(int i=s; i<s+(n-s)/2; i++){
        c = i-s;
        temp = arr[i];
        arr[i] = arr[n-1-c];
        arr[n-1-c] = temp;
    }
}
void printArray(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int n,d;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr1[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0; i<n; i++)
        cin>>arr1[i];
    cout<<"Enter the value of d: ";
    cin>>d;
    reverse(arr1,0,d);
    printArray(arr1,n);
    reverse(arr1,d,n);
    printArray(arr1,n);
    reverse(arr1,0,n);
    cout<<"Array after rotation is: ";
    printArray(arr1,n);
    return 0;
}