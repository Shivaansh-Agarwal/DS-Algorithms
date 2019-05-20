// Bitwise Operations
// Check if k'th bit is set or not (From Right).
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter a Number: \n";
    cin>>n;
    cout<<"Enter the bit you want to check?\n";
    cin>>k;
    if(k>32){
        cout<<"Invalid Input";
        exit(0);
    }
    else{
        if((n&(1<<(k-1))) != 0)
            cout<<"True";
        else
            cout<<"False";
    }
}