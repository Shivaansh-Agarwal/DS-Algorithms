/*
    PROBLEM STATEMENT
    Given a String, Remove any pair of duplicates.

    I/P: aaabbaaccd
    O/P: ad

    I/P: aaaa
    O/P: Empty String
*/
//#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removePair(string str){
    stack<char> s;
    string::iterator it;
    for(it=str.begin();it<str.end();it++){
        if(s.empty()){
            s.push(*it);
        }
        else if(s.top()==*it){
            s.pop();
            continue;
        }
        else{
            s.push(*it);
        }
    }
    string ans = "";
    if(s.empty()){
        ans = "Empty String";
    }
    else{
        while(!s.empty()){
            ans = ans + s.top();
            s.pop();
            continue;
        }
        reverse(ans.begin(),ans.end());
    }
    return ans;
}
int main(){
    string str;
    getline(cin,str);
    string ans = removePair(str);
    cout<<ans<<endl;
}