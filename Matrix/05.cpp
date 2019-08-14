/*
    PROBLEM STATEMENT:
        Given a Matrix, Print the boundary elements.
    
    I/P:                O/P:
    1 2 3 4             1 2 3 4 8 12 11 10 9 5
    5 6 7 8
    9 10 11 12
*/
#include<iostream>
using namespace std;
void printBoundary(int *arr, int r, int c){
    int i = 0;
    int j;
    //First Row
    for(j=0;j<c;j++)
        cout<<*(arr+i*c+j)<<" ";
    //Last Column
    j = c-1;
    for(int i=1;i<r;i++)
        cout<<*(arr+i*c+j)<<" ";
    //Last Row
    i = r-1;
    for(int j=c-2;j>=0;j--)
        cout<<*(arr+i*c+j)<<" ";
    //First Column
    j = 0;
    for(int i=r-2;i>=1;i--)
        cout<<*(arr+i*c+j)<<" ";
}
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
    printBoundary((int *)arr,r,c);
    return 0;
}