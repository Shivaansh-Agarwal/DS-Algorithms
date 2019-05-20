#include<iostream>
using namespace std;
// Given a Number N, determine whether it is even or odd

int main(){
	int n;
	cin>>n;
	if((n&1) == 0)
		cout<<"Even";
	else
		cout<<"Odd";
	return 0;
}
