/*
    PROBLEM STATEMENT:
    Find the most frequent element in an array.
    I/P: arr[] = {5,6,8,3,6,8,5,6,6}
    O/P: 6
*/
#include<iostream>
#include<unordered_map>
using namespace std;
int* find_max(int *arr,int n){
    static int ans[2];
    unordered_map<int,int> unmap;
    for(int i=0;i<n;i++){
        if(unmap.find(arr[i])==unmap.end()){
            // if element is not present in the map
            unmap[arr[i]] = 1;
        }
        else{
            // if element is present in the map
            unmap[arr[i]] = unmap[arr[i]]+=1;
        }
    }
    int max_elem, max_freq;
    bool temp = false;
    for(auto x: unmap){
        if(!temp){
            max_elem = x.first;
            max_freq = x.second;
            temp = true;
        }
        else{
            if(x.second>max_freq){
                max_freq = x.second;
                max_elem = x.first;
            }
        }
    }
    ans[0] = max_elem;
    ans[1] = max_freq;
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elments in the array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int* ans = find_max(arr,n);
    cout<<"Maximum Element: "<<ans[0]<<" has frequency: "<<ans[1];
    return 0;
}