//Factorial with Tail Recursion
#include<iostream>
using namespace std;
factorial(int n, int res = 1){
    if(n==1 || n==0)
        return res;
    else
        return factorial(n-1,n*res);
}
int main(){
    int n,ans;
    cin>>n;
    ans = factorial(n);
    cout<<"Factorial of "<<n<<" = "<<ans;
    return 0;
}