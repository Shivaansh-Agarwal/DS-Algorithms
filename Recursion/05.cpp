// Given a rope of length n and 3 values (a,b,c), we need to make maximum pieces such that every piece has length in set {a,b,c}
/*
    I/P: n=5, a=1, b=2, c=3
    O/P: 5 (5*a + 0*b + 0*c)

    I/P: n=23, a=9, b=11, c=12
    O/P: 2 (0*a | 1*b | 1*c)

    I/P: n=5, a=2, b=4, c=6
    O/P: -1
*/
#include<iostream>
using namespace std;
int maxpieces(int n, int a, int b, int c){
    if(n<0)//When
        return -1;
    if(n==0)
        return 0;
    int A = maxpieces(n-a,a,b,c);
    int B = maxpieces(n-b,a,b,c);
    int C = maxpieces(n-c,a,b,c);
    
    // Finding Maximum of A,B,C
    int res;
    if(A>=B && A>=C)
        res = A;
    else if(B>=C)
        res = B;
    else
        res = C;
    
    if(res==-1)
        return -1;
    else
        return res+1;
}
int main(){
    int n,a,b,c;
    int ans;
    cin>>n>>a>>b>>c;
    ans = maxpieces(n,a,b,c);
    cout<<"Maximum Pieces = "<<ans;
    return 0;
}