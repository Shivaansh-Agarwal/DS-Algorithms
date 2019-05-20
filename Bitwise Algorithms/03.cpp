#include<iostream>
using namespace std;
// Given a number N, determine whether it is a power of 2 or not
/*
	A number which is power of 2 has only 1 bit set,
	Ex: 4 => 100
	So if we do Bitwise & of this number with it's predecessor i.e. 3 => 011
	We'll get 0
	So, if((n & (n-1)) == 0)
			print("Power of 2");
		else
			print("Number is not a power of 2");
*/
int main(){
	int n;
	cin>>n;
	if((n & (n-1)) == 0)
		cout<<"Power of 2";
	else
		cout<<"Number is not a power of 2";
	return 0;
}
