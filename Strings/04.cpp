/* 
    PROBLEM STATEMENT
    Given a string, find its rank among all its permutations sorted lexicographically. 
    For example, rank of “abc” is 1, rank of “acb” is 2, and rank of “cba” is 6.
    [The String does not contain any duplicate characters.]

    I/P: s="acb"
    O/P: 2
    Explanation:
    1 abc
    2 acb
    3 bac
    4 bca
    5 cab
    6 cba
*/
#include<iostream>
#include<string>
using namespace std;
int factorial(int n){
    int p = 1;
    if(n==0 || n==1)
        return 1;
    while(n>=1){
        p = n*p;
        n--;
    }
    return p;
}
int getLexicographicRank(string s){
    // Function for strings which contain no Repeating character
    
    // Count array to store which characters are present in the String
    int count[256] = {0};
    for(int i=0;i<s.length();i++)
        count[s[i]]+=1;
    
    // Cumulative Frequency Array to store the frequency of how many charcaters, which are present in the string,
    // are smaller than the character.
    int cumulFreq[256] = {0};
    int temp = 0;
    if(count[0]==1)
        temp = 1;
    for(int i=1;i<256;i++){
        if(count[i]==1){
            cumulFreq[i] = temp;
            temp++;
        }
    }
    /*
    for(int i=0;i<256;i++)
        cout<<cumulFreq[i]<<" ";
    */

    int n = s.length();
    int smaller,fact,sum = 0;
    for(int i=0;i<n-1;i++){
        smaller = cumulFreq[s[i]];
        fact = factorial(n-(i+1));
        sum = smaller*fact + sum;
    }

    return sum+1;
}
int main(){
    string str;
    cout<<"Enter String: ";
    getline(cin,str);
    int rank = getLexicographicRank(str);
    cout<<"Lexicographic Rank of String "<<str<<" : "<<rank<<endl;
    return 0;
}


