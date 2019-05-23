// Josephus Problem
/*
    Given the total number of persons n and a number k which indicates that 
    k-1 persons are skipped and k'th person is killed in circle in a fixes direction.
    The task is to choose the safe place in the circle so that when you 
    perform these operations starting from 1st place in the circle, you're the last
    one remaining and survive.
*/
#include<iostream>
using namespace std;
int josephus(int n, int k){
    if(n==1)
        return 1;
    else
        return (josephus(n-1,k) + k-1)%n+1;
        
}
int main(){
    int n,k,ans;
    cin>>n>>k;
    ans = josephus(n,k);
    cout<<"Position of person saved is: "<<ans;
    return 0;
}
/*
    If we use josephus(n-1,k) as Recursion Equation
        For n=5, k=2
        We get ans = 1,
        BUT we know that the correct ans is 3.
        In this case we're only considering that one person is killed at each recursion,
        BUT we are not considering that the position of the people standing ahead the person killed will also get chnaged.
*/