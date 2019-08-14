/*
    PROBLEM STATEMENT:
    Search an element in a row wise and column wise sorted matrix.

    I/P: 
    10 20 30        x=35
    15 25 80
    35 90 100

    O/P:
    The element is present and it's location is 2,0
*/
#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter the number of rows and columns of the matrix: ";
    cin>>r>>c;
    int arr[r][c];
    cout<<"Enter the elements in the matrix: ";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    int x;
    cout<<"Enter the element to be searched: ";
    cin>>x;
    
    // I'll start from the top right position.
    int j=c-1;
    bool found = false;
    for(int i=0;(i<r)&&(j>=0)&&(i>=0);i++){
        if(arr[i][j]==x){
            cout<<"The element is present and it's location is "<<i<<","<<j;
            found = true;
            break;
        }
        else if(arr[i][j]<x){
            continue;
        }
        else if(arr[i][j]>x){
            j--;
            i--;//Because in the next line we're sending the control back to the starting of loop so I'll will remain the same.
            continue;
        }
    }

    if(!found)
        cout<<"Element not found"<<endl;
    
    return 0;
}