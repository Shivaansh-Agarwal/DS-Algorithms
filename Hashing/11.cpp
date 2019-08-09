/* 
    PROBLEM STATEMENT
    Given an unsorted array and a number x, find if there is a pair with sum x.

    I/P: arr[] = {2,6,8,12,4,5}, s=8;
    O/P: true

    I/P: arr[] = {5,9,2,11,99}, s=4 
    O/P: false  //Here 2 should not be considered twice

    APPROACH: Using Hashing O(n)
*/
#include<iostream>
#include<unordered_map>
// Here I've used unordered_map since I also want to store the Frequency of all elements.
using namespace std;
void isPairPresent(int *arr, int n, int s){
    //First I need to calculate the frequency of all the elements in the array and store it in an unordered_map.
    unordered_map <int,int> umap;
    int elem;
    for(int i=0;i<n;i++){
        elem = arr[i];
        if(umap.find(elem)!=umap.end()){
            umap.find(elem)->second += 1;
        }
        else{
            umap[elem] = 1;
        }
    }
    int rem;
    for(int i=0;i<n;i++){
        rem = s-arr[i];
        umap.find(arr[i])->second -= 1;
        if(umap.find(rem)!=umap.end() && umap.find(rem)->second!=0){
            cout<<"Elements Found "<<arr[i]<<" & "<<rem;
            return;
        }
        umap.find(arr[i])->second += 1;
    }
    cout<<"Paired elements not found";
}
int main(){
    int n,s;
    cout<<"Enter the number of elements you want to enter: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the Sum: ";
    cin>>s;
    isPairPresent(arr,n,s);
    return 0;
}
