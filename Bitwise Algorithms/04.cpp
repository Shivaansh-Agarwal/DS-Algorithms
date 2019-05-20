#include<iostream>
using namespace std;

// Given a number N, determine the number of set bits.
/*
	Ex: N=26 => 11010
	Ans=3
	
	One approach for solving this could be to use loop and checking for each bit whether it's set or not,
	BUT it takes O(total no. of bits representation), i.e. if total bit representation is 32, it'll take 32 iterations
	
	There's one other approach, that will take only k iterations, where k is the number of bits set.
	For this we'll use the 'Brian Karnighan Algorithm'
	
	So for example, we've 26 => 11010 as the I/P
	So it'll perform following operations, and we'll count the number of iterations and that would be our ANSWER.
	11010
	||
	11000 (1st Iteration)
	||
	10000 (2nd Iteration)
	||
	00000 (3rd Iteration) [STOP]
	
	But How will we remove the last set bit in every iteration
	For this, we will perform Bitwise & of the number in the present iteration and it's predecessor.
	Therefore to remove last set bit from 11010 we'll perform =>  11010 & 11001 => 11000
*/
int main(){
	int n,result=0;
	cin>>n;
	while(n>0){
		n = n&(n-1);
		result++;
	}
	cout<<result;
	return 0;
}
