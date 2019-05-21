//Given a number N determine the XOR of all numbers from 1 to N WITHOUT using Loops.
// Link => https://www.geeksforgeeks.org/calculate-xor-1-n/
/*
	N = 6
	Output = 7
	// 1^2^3^4^5^6 = 7
	
	N = 7
	Output = 0
	// 1^2^3^4^5^6^7 = 0
*/
#include<iostream>
using namespace std;
int main(){
	int n,temp;
	cin>>n;
	temp = n%4;
	if(temp==0)
		cout<<"XOR: "<<n;
	else if(temp==1)
		cout<<"XOR: "<<1;
	else if(temp==2)
		cout<<"XOR: "<<n+1;
	else if(temp==3)
		cout<<"XOR: "<<0;
	return 0;
}
