// Bubble Sort
#include<iostream>
using namespace std;
int* bubbleSort(int arr[], int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;   
            }
        }
    }
    return arr;
}
void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main(){
    int n;
    cout<<"Enter the nunber of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int size = sizeof(arr)/sizeof(arr[0]);
    int *arrSorted = bubbleSort(arr,n);
    printArray(arrSorted,n);
    return 0;
}