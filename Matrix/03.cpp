/*
    PROBLEM STATEMENT:
    Rotate a Matrix by 90 degree counter clockwise.

    I/P: 1 2 3              O/P: 3 6 9
         4 5 6                   2 5 6
         7 8 9                   1 4 7


    If noticed carefully we first Transpose the Matrix, then reverse the columns.
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

    // Learn how to pass and return 2D Array to and from a Function in C++ and then,
    // Write function for transpose and rotation of a Matrix
    
    //Transpose of a Matrix
    int temp;
    for(int i=0;i<r;i++){
        for(int j=i+1;j<c;j++){
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // Rotation of every column of a Matrix
    for(int j=0;j<c;j++){
        for(int i=0;i<r/2;i++){
            temp = arr[i][j];
            arr[i][j] = arr[r-(i+1)][j];
            arr[r-(i+1)][j] = temp;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}