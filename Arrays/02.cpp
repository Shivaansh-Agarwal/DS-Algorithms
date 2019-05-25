// Rotate an Array (Naive Method)
/*
    I/P=>
        arr[] = {5,8,10,12,15}
        d = 2
    O/P=>
        arr = {10,12,15,5,8}
*/
/*
    ALGORITHM
    1. We store all the n elements in array named arr1[n].
    2. We declare another array named arr2[d].
    3. In this array arr2 we copy the first d elements of arr1.
    4. After this we need to shift the elements after these first d elements to the beginning
*/
#include<iostream>
using namespace std;
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
    // Copying first d elements to another array arr2[d] 
    int arr2[d];
    for(int i=0;i<d;i++)
        arr2[i] = arr1[i];
    // Shift elements of array arr1 after first d elements to the beginning
    for(int i=d;i<n;i++)
        arr1[i-d] = arr1[i];
    // Copy the elements of array arr2[d] to the array arr1[n] after the elements which have been shifted.
    int j=0;
    for(int i=n-d;i<n;i++){
        arr[i] = arr2[j];
        j++;
    }
    // Printing the elements after rotation
    cout<<"Array after rotation is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}