// Given a number N. Find the count of number of set bits from 1 to N
/*
	I/P=> 4
	O/P=> 5
		1=> 0001 -> 1
		2=> 0010 -> 1
		3=> 0011 -> 2
		4=> 0100 -> 1
			TOTAL=> 5
	
	I/P=>17
	O/P=>35
*/
#include<iostream>
using namespace std;
int main(){
	int x;
	cin>>x;
	int count = 0;
    for(int i=1;i<=x;i++){
        int n = i;
        while(n>0){
            n = n&(n-1);
            count++;
        }
    }
    cout<<count;
}
