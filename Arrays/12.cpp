/*
    Frequencies of Array Elements in a Given Range
    
    Given an Array A[] of N +ve integers which can contain integers from 1 to N,
    where elements can be repeated or can be absent from the array.
    The task is to count the frequencies of all the elements frim 1 to N.
    NOTE: Expected time complexity is O(n) with O(1) extra space complexity.

    I/P:
        n = 5                       n = 4
        arr[] = 2,3,2,3,5           arr[] = 3,3,3,3
    O/P:            
        0 2 2 0 1                   0 0 4 0
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    // Subtract 1 from every element so that the elements become in range 0 to 1
    for(int i=0;i<n;i++)
        arr[i] = arr[i] - 1;
    
    // We use every element arr[i] as index and add 'n' to element present at arr[i]%n to keep
    // track of count of occurences of arr[i]
    for(int i=0;i<n;i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;
    
    // For every element subtract arr[i]%n from it and then divide it by n
    for(int i=0;i<n;i++)
        cout<<(arr[i]-(arr[i]%n))/n<<" ";

    cout<<endl;
    return 0;
}