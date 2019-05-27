#include<iostream>
#include<vector>
using namespace std;
vector<int> reverseInGroups(vector<int>,int,int);
int main(){
    int n,k,x;
    cin>>n>>k;
    vector<int> mv;
    for(int i=0;i<n;i++){
        cin>>x;
        mv.push_back(x);
    }
    mv = reverseInGroups(mv,n,k);
    for(int i=0;i<n;i++)
        cout<<mv[i]<<" ";
    return 0;
}
vector<int> reverseInGroups(vector<int> mv, int n, int k){
    int temp;
    for(int i=0; i<n; i+=3){
        if((i+k)<n){
            for(int j=i; j<(i+k)/2; j++){
                temp = mv[j];
                mv[j] = mv[i+k-1-j];
                mv[i+k-1-j] = temp;
            }
        }
        else if(i==n-1){
            break;
        }
        else if(i==n-2){
            temp = mv[i];
            mv[i] = mv[i+1];
            mv[i+1] = temp;
            break;
        }
        else{
            for(int j=i; j<(i+n-1)/2; j++){
                temp = mv[j];
                mv[j] = mv[n-1-j];
                mv[n-1-j] = temp;
            }
        }
    }
    return mv;
}
