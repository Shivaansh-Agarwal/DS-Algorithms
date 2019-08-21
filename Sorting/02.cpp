// Selection Sort
// It selects the maximum element in every iteration and then swaps that element with the last unsorted element in the array.

#include<iostream>
using namespace std;
int* getInput(int n){
    static int *arr = new int[n];
    cout<<"Enter the elements in the Array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    return arr;
}
// void printArray(int arr[], int n)
void printArray(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void swap(int *lastUnsorted, int *max){
    int temp = *max;
    *max = *lastUnsorted;
    *lastUnsorted = temp;
}
void selectionSort(int arr[], int n){
    int max,loc,temp;
    int j;
    for(int i=0;i<n-1;i++){
        max = arr[0];
        loc = 0;
        for(j=1;j<n-i;j++){
            if(arr[j]>max){
                max = arr[j];
                loc = j;
            }
        }
        //arr[j-1] => Represents the last unsorted element int the array.
        //arr[loc] => The greatest element in the unsorted array.
        swap(arr[j-1],arr[loc]);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    int *arr = getInput(n);
    selectionSort(arr,n);
    printArray(arr,n);
}