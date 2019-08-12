/*
    PROBLEM STATEMENT
    Find Transpose of a Matrix.
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
    int temp;
    for(int i=0;i<r;i++){
        for(int j=i+1;j<c;j++){
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    //Printing the elements
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}