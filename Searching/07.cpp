/*
    Given an array arr[] of N positive integers, where elements are consecutive (sorted).
    Also, there is a single element which is repeating X (any variable) number of times.
    Now, the task is to find the element which is repeated and number of times it is repeated.
*/
/*
    I/P:
        t = 2                       
        n = 5                       n = 5
        arr[] = 1 2 3 3 4           arr[] = 2 3 4 5 5
    O/P:
        3 2                         5 2
*/
#include <iostream>
using namespace std;
int main() {
	//code
	int t;// Number of test cases
	cin>>t;
	while(t-->0){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    int index;
	    for(int i=0;i<n-1;i++){
	        if(arr[i]==arr[i+1]){
	            index = i;
	            break;
	        }
	    }
	    int count = 0;
	    for(int i=index;i<n-1;i++){
	        if(arr[i]==arr[i+1])
	            count++;
	    }
	    cout<<arr[index]<<" "<<count+1<<endl;
	}
	return 0;
}