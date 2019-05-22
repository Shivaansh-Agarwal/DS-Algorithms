// Factorial using Recursion
#include<iostream>
using namespace std;
int factorial(int);
int main(){
    int n,ans;
    cin>>n;
    ans = factorial(n);
    cout<<"Factorial of "<<n<<" = "<<ans;
    return 0;
}
int factorial(int n){
    if(n==1 || n==0)
        return 1;
    else
        return n*factorial(n-1);
}