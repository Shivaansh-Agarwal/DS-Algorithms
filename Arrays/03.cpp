// Rotating an Array (using Reverse Operation 3 times)
// Time Complexity => O(n)
// Space Complexity => O(n)
#include<iostream>
using namespace std;
/*
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
*/
void rotateArr(int arr[], int d, int n){
    // Your code here
    int temp;
    for(int i=0;i<d/2;i++){
        temp = arr[i];
        arr[i] = arr[d-1-i];
        arr[d-1-i] = temp;
    }
    int j=0;
    for(int i=d; i<(d+n)/2; i++){
        temp = arr[i];
        arr[i] = arr[n-1-j];
        arr[n-1-j] = temp;
        j++;
    }
    for(int i=0;i<n/2;i++){
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
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
    /*
    reverse(arr1,0,d);
    reverse(arr1,d,n);
    reverse(arr1,0,n);
    */
    rotateArr(arr1,d,n);
    cout<<"Array after rotation is: ";
    printArray(arr1,n);
    return 0;
}