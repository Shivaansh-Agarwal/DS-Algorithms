/*
    PROBLEM STATEMENT
    Find the largest subarray with Given Sum x.

    I/P: arr[] = {5,3,8,-4,1,3,4,3}; x=11
    O/P: Largest Subarray with sum x=11 is from 4 to 7.
*/
#include<iostream>
#include<unordered_map>
using namespace std;
void largestSubArray(int arr[], int n, int x){
    unordered_map<int, int> umap;
    int max_length = 0;
    int l_index,r_index;//For storing the beginning and ending of the subarray
    /*
        First I'll find the subarray with given sum, and store it's l_index, r_index and length;
        Then I'll move further and see whether any more subArray with given sum are present or not..
    */
    umap[0] = 0;
    int preSum = 0;
    bool temp = false;
    for(int i=0;i<n;i++){
        preSum += arr[i];
        if(umap.find(preSum-x)!=umap.end()){
            if(i==0){
                temp = true;
                max_length = 1;
                l_index=0;
                r_index=0;
                preSum = 0;
            }
            else{
                temp = true;
                l_index = umap.find(preSum-x)->second+1;
                r_index = i;
                if((r_index-l_index+1)>max_length){
                    max_length = r_index-l_index+1;
                }
                preSum = 0;
            }
        }
        umap[preSum] = i;
    }
    if(temp)
        cout<<"Largest Subarray with sum="<<x<<" is from index "<<l_index<<" to "<<r_index;
    else
        cout<<-1;
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
    largestSubArray(arr,n,x);
    return 0;
}