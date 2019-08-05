/* 
    PROBLEM STATEMENT
    Given an array, print the frequency of every element.
*/
#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,int> findFreq(int *arr, int n){
    static unordered_map<int, int> unmap;
    for(int i=0;i<n;i++){
        if(unmap.find(arr[i])==unmap.end()){
            unmap[arr[i]]=1;
        }
        else{
            unmap[arr[i]] = unmap[arr[i]]+=1;
        }
    }
    // for(auto x: unmap){
    //     cout<<x.first<<" => "<<x.second<<endl;
    // }
    return unmap;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elments in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    unordered_map<int, int> unmap;
    unmap = findFreq(arr,n);
    for(auto x: unmap){
        cout<<x.first<<" => "<<x.second<<endl;
    }
    return 0;
}