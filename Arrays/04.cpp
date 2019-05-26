//Leaders in an Array (Naive Approach)
/*
    arr[] = {5,3,20,15,8,3}
    Leaders = 20 15 8 3

    arr[] = {5,3,20,15,8,25,3}
    Leaders = 25 3
*/
/*
    Time Complexity => O(n^2)
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int elem;
    bool temp;
    for(int i=0;i<n-1;i++){
        temp=true;
        elem = arr[i];
        for(int j=i+1;j<n;j++){
            if(elem<arr[j]){
                temp = false;
                break;
            }
        }
        if(temp)
            cout<<elem<<" ";
    }
    cout<<arr[n-1];
    return 0;
}