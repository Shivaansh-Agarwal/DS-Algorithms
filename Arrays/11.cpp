// Maximum Occured Integer in given Ranges
/*
    Given two arrays L[] and R[] consisting of N ranges of the form L and R, 
    L[i] consists of starting point of range and R[i] consists of corresponding 
    end point of the range. The task is to find the maximum occurred integer in all the ranges. 
    If more than one such integer exits, print the smallest one.

    Ex:
        I/P:
            4               5
            1 4 3 1         1 5 9 13 21
            15 8 5 4        15 8 12 20 30
        O/P:   
            4               5
*/
#include<iostream>
using namespace std;
int max1(int arr[], int n){
    int maxx = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>maxx)
            maxx = arr[i];
    }
    return maxx;
}
int max_occur(int L[], int R[], int n, int arrSize){
    int arr[arrSize+2] = {0};
    for(int i=0;i<n;i++){
        arr[L[i]]+=1;
        arr[R[i]+1]-=1;
    }
    // finding prefix sum of array (Cumulative Sum)
    for(int i=1;i<arrSize;i++){
        arr[i] += arr[i-1];
    }
    int max_arr = max1(arr,arrSize);
    int ans;
    for(int i=0;i<arrSize;i++){
        if(arr[i]==max_arr){
            ans = i;
            break;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of n: ";
    cin>>n;
    int L[n], R[n];
    cout<<"Enter the elements in L: ";
    for(int i=0;i<n;i++)
        cin>>L[i];
    cout<<"Enter the elements in R: ";
    for(int i=0;i<n;i++)
        cin>>R[i];
    // Now we'll find the maximum element in R[] so that we can determine the size of arr
    int arrSize = max1(R,n);
    int ans;
    ans = max_occur(L,R,n,arrSize);
    cout<<ans;
    return 0;
}