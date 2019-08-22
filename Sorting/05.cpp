#include<iostream>
using namespace std;

int* getInput(int n){
    int *arr = new int[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    return arr;
}

void printArray(int *arr,int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void merge(int *arr, int left, int mid, int right){
    // This function merges the 2 sorted subarrays
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for(int i=0;i<n1;i++)
        L[i] = arr[left + i];
    for(int j=0;j<n2;j++)
        R[j] = arr[mid + 1 + j];
    
    int i=0, j=0, k=left;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int *arr = getInput(n);
    mergeSort(arr,0,n);
    printArray(arr,n);
    return 0;
}