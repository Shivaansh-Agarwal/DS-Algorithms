/* 
    PROBLEM STATEMENT
    Find the smallest subarray with a given sum.

    I/P: arr[] = {5,7,3,6,1,3,1,4}; x=5;
    O/P: Smallest Subarray with sum=5 is present from index 0 to 0.
*/
#include<iostream>
#include<unordered_map>
using namespace std;
void smallestSubArray(int arr[], int n, int x){
    unordered_map<int,int> umap;
    bool temp = false;
    int min_length = 0;
    int l_index, r_index, l_index_1, r_index_1;
    umap[0] = 0;
    int preSum = 0;
    for(int i=0;i<n;i++){
        preSum += arr[i];
        if(umap.find(preSum-x)!=umap.end()){
            // if preSum-x is present in the map
            // if it's the first element
            if(i==0){
                temp = true;
                min_length = 1;
                l_index = 0;
                r_index = 0;
                preSum = 0;
                continue;
            }
            else{
                temp = true;
                l_index_1 = umap.find(preSum-x)->second+1;
                r_index_1 = i;
                if((r_index_1-l_index_1+1)<min_length){
                    min_length = r_index-l_index+1;
                    l_index = umap.find(preSum-x)->second+1;
                    r_index = i;
                }
                preSum = 0;
                continue;
            }
        }
        umap[preSum] = i;
    }
    if(temp)
        cout<<"Smallest SubArray with sum= "<<x<<" is present from index "<<l_index<<" to "<<r_index;
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
    smallestSubArray(arr,n,x);
    return 0;
}
