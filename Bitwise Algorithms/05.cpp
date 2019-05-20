// Given an array that contains every element even number of times, except one element. Find that number.
#include<iostream>
using namespace std;
int main(){
	int n,ans=0;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the elements in the array: ";
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ans = ans^arr[i];
	}
	cout<<ans;
	return 0;
}
