/* 
    PROBLEM STATEMENT
    Given an array and a sum x find if there is subarray where sum is aqual to x.

    I/P: arr[] = {5,3,8,-2,8,10}, x=11
    O/P: true

    I/P: arr[] = {5,3,8,-2,8,10}, x=5
    O/P: true
*/
#include<iostream>
#include<unordered_map>
using namespace std;
void isSubArrayPresent(int arr[], int n, int x){
    int preSum = 0;
    unordered_map<int,int> umap;
    umap[0]=0;//To handle the case when x=arr[0].
    for(int i=0;i<n;i++){
        preSum += arr[i];
        if(umap.find(preSum-x)!=umap.end()){
            if(i==0){
                cout<<"Subarray found at index 0";
                return;
            }
            else{
                cout<<"Subarray found from index "<<(umap.find(preSum-x)->second)+1<<" to "<<i;
                return;
            }
        }
        umap[preSum]=i;
    }
    cout<<"-1";
}
int main(){
    int n,x;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the value of x: ";
    cin>>x;
    isSubArrayPresent(arr,n,x);
}