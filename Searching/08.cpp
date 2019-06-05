/*
    Kth smallest element

    Given an array arr[] and a number K where K is smaller than size of array,
    the task is to find the Kth smallest element in the given array. 
    It is given that all array elements are distinct.

    Expected Time Complexity: O(n)
*/
/*
    I/P:                                
        n = 6
        arr[] = 7 10 4 3 20 15
        k = 3                           
    O/P:
        7

    I/P:
        n = 5
        arr[] = 7 10 4 20 15
        k = 4
    O/P:
        15
*/
#include<iostream>
using namespace std;
int main(){
    int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	    cin>>arr[i];
    int k;
    	cin>>k;
	/* 
	    1. Find the maximum element in this arr
        2. Declare an array arr2 of size max and initialize each element by false
	    3. Iterate through the array arr and make the corresponding index in
	        arr2 equal to true.
	    4. Traverse the array arr2 and print the kth value which is true.
	*/ 
	int max = arr[0];
	for(int i=1;i<n;i++){
	    if(arr[i]>max){
	        max = arr[i];
	    }
	}
	bool arr2[max+1] = {false};
	for(int i=0;i<n;i++){
	    arr2[arr[i]] = true;
	}
	int count = 0;
	for(int i=1;i<max+1;i++){
	    if(arr2[i]==true)
	        count++;
	    if(count==k){
	       cout<<i<<endl;
	        break;
	    }
    }
    return 0;
}