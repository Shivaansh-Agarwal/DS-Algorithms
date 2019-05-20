// Given a number N determine the position of the first set bit
/*
	Example:
	I/P-> N = 110010	I/P-> N = 110101000		I/P-> N=111
	O/P-> 2				O/P-> 4					O/P-> 1
*/

#include<iostream>
using namespace std;
int main(){
	int n,ans=1,k=1;
	cin>>n;
	while(true){
		if((n&(1<<(k-1)))==0){
			ans++;
			k++;
		}
		else
			break;
	}
	cout<<ans;
	return 0;
}
