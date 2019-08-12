/*
    PROBLEM STATEMENT: Print the matix in Snake Pattern
*/
#include<iostream>
using namespace std;
void printInSnakePattern(int r, int c, int *arr){
    bool rotate = true;
    for(int i=0;i<r;i++){
        if(rotate){
            for(int j=0;j<c;j++){
                cout<<*(arr+i*c+j)<<" ";
            }
            rotate = false;
            continue;
        }
        else{
            for(int j=c-1;j>=0;j--){
                cout<<*(arr+i*c+j)<<" ";
            }
            rotate = true;
            continue;
        }
    }
}
int main(){
    int m,n;
    cout<<"Enter the number of rows and columns of the matrix: ";
    cin>>m>>n;
    int arr[m][n];
    cout<<"Enter the elements in the matrix: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    printInSnakePattern(m,n,(int *)arr);
}