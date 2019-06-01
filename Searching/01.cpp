// Linear Search

#include<iostream>
using namespace std;
void lsearch(int arr[], int n, int x){
    bool found = false;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            cout<<"Element found at location "<<i+1;
            found=true;
            break;
        }
    }
    if(!found)
        cout<<"Element not found";
}
int main(){
    int n,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>x;
    lsearch(arr,n,x);
    return 0;
}