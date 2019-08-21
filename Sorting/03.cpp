// Insertion  Sort
// It sorts the way we humans do

#include<iostream>
using namespace std;
int* getInput(int n){
    static int *arr = new int[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    return arr;
}
void insertionSort(int *arr, int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j-=1;
        }
        arr[j+1] = key;
    }
}
void printArray(int *arr, int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    int *arr = getInput(n);
    insertionSort(arr,n);
    printArray(arr,n);
}