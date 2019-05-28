// Reverse Array in Groups [Efficient Solution using vectors and reverse() of algorithm]
/*
    Given an array arr[] of positive integers of size N. Reverse sub-array of K-group elements.
    I/P:                I/P:
        5 3                 4 3
        1 2 3 4 5           5 6 8 9
    // Here n=5 k=3 
    O/P:                O/P:
        3 2 1 5 4           8 6 5 9
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> reverseInGroups(vector<long long>,int,int);
int main(){
    int n,k,x;
    cin>>n>>k;
    vector<long long> mv;
    for(int i=0;i<n;i++){
        cin>>x;
        mv.push_back(x);
    }
    mv = reverseInGroups(mv,n,k);
    for(int i=0;i<n;i++)
        cout<<mv[i]<<" ";
    return 0;
}
vector<long long> reverseInGroups(vector<long long> mv, int n, int k){
    for(int i=0;i<n;i+=k){
        if((i+k)<n)
            reverse(mv.begin()+i,mv.begin()+i+k);
        else
            reverse(mv.begin()+i,mv.end());
    }
    return mv;
}
