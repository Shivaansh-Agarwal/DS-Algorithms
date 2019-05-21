//Given two numbers A and B. Count number of bits needed to be flipped to convert A to B.
/*
	Example,
	I/P=>	A = 10, B = 20
	O/P=>	4
	
		A  = 01010
		B  = 10100
	
	If we take XOR of these 2 numbers, and then count number of set bits in that number, we get the answer.
*/
#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int n = a^b;
    int count=0;
    while(n>0){
        n = n&(n-1);
        count++;
    }
    cout<<count;
    return 0;
}
