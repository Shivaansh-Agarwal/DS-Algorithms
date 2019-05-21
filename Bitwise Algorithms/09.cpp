// Given a number N, determine the position & value of the most significant digit
/*
	For Example,
		N = 10 => (1010)
		O/P=>
			Position = 4
			Value = 8
*/
/*
	Property of Log
	loga(b) = loge(a)/loge(b)
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,position,value;
	cin>>n;
	position = log2(n);
	value = 1<<position;
	cout<<"Position: "<<position<<"\nValue: "<<value;
	return 0;
}
