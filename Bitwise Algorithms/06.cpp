// Given an integer array that contains every number even number of times, except 2 numbers. Find the 2 numbers.
/*
	STEPS:
		1. Take XOR of all elements in the array
		2. Find the position of set bit of this XOR number (I've taken first(rightmost) set bit), let that be 'k'.
		3. Now iterate the elements of array and see which element has k'th bit set.
		   In the Array either the element will have that bit set at k'th position or not.
		   So basically the array elements will be divided into 2 groups.
		4. Take XOR of every element of both groups.
		5. The result of XOR's will be the Answer.
*/
#include<iostream>
using namespace std;
int main(){
	int n,xor1=0;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the elements in the array: ";
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		xor1^=arr[i];
	}
	//cout<<"XOR1: "<<xor1<<endl;
	// Now we need to find the leftmost set bit of this XOR term
	int k=1;
	while(true){
		if( (xor1&(1<<(k-1))) !=0 )
			break;
		else{
			k++;
			continue;
		}
	}
	//cout<<k;
	// Now we'll check whether the k'th bit of a number is set or not in the array and then divide them into 2 groups & take XOR of all elements.
	int num1=0,num2=0;
	for(int i=0;i<n;i++){
		if((arr[i]&(1<<k))!=0)
			num1^=arr[i];
		else
			num2^=arr[i];
	}
	cout<<"Number 1: "<<num1<<"\nNumber 2: "<<num2;
	return 0;
}
