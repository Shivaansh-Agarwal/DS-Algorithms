/* 
    PROBLEM STATEMENT:
    Given a binary array find length of the largest subarray having equal number of 0's and 1's

    I/P: arr[] = {0,1,1,0,1,1,0}
    O/P: 4

    I/P: arr[] = {1,1,1,1}
    O/P: 0

    I/P: arr[] = {1,1,1,1,0,0,1,1,1,1,0,0}
    O/P: 8
*/
#include<iostream>
#include<unordered_map>
using namespace std;
int findLength(int *arr,int n){
    unordered_map<int,int> umap;
    umap[0] = 0;
    int preSum = 0;
    int l_index=-1,r_index=-1,length=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            preSum += -1;
        }
        else
            preSum += 1;
        if(preSum==0 && length==0){
            //If Subarray starts from the beginning and it's the first Subarray to be found.
            l_index = 0;
            r_index = i;
            length = r_index-l_index+1;
            continue;
        }
        else if(preSum==0 && length!=0){
            //If Subarray starts from the beginning and it's not the first Subarray to be found.
            if((i+1)>length){
                // If this Subarray is greater than the previously largest subarray found
                l_index = 0;
                r_index = i;
                length = r_index-l_index+1;
                continue;
            }
        }
        else if(umap.find(preSum)!=umap.end() && length==0){
            // If Subarray doesn't start from the beginning and it's the First Subarray to be found.
            l_index = umap.find(preSum)->second+1;
            r_index = i;
            length = r_index-l_index+1;
            continue;
        }
        else if(umap.find(preSum)!=umap.end() && length!=0){
            // If Subarray doesn't start from the beginning and it's not the First Subarray to be found.
            if((i-umap.find(preSum)->second+1)+1>length){
                l_index = umap.find(preSum)->second+1;
                r_index = i;
                length = r_index-l_index+1;
                continue;
            }
        }
        umap[preSum] = i;
    }
    if(length!=0){
        cout<<"l_index: "<<l_index<<" r_index: "<<r_index<<endl;
    }
    return length;

}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans = findLength(arr,n);
    cout<<"Length of largest subarray having equal number of 0's and 1's is: "<<ans;
    return 0;
}