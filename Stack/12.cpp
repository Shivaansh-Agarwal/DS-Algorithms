// Given a string, remove the consecutive duplicates from it.
/*
    I/P: aaaaaabaabccccccc
    O/P: ababc

    I/P: abbccbcd
    O/P: abcbcd
*/
#include<bits/stdc++.h>
/*
#include<iostream>
#include<algorithm> // For using reverse function
*/
using namespace std;
string removeConsecutiveDuplicates(string str){
    stack<char> s;
    string::iterator it;
    for(it=str.begin();it<str.end();it++){
        if(s.empty()){
            // For pushing first Element into the Stack
            s.push(*it);
        }
        else if(s.top()==*it)
            continue;
        else{
            s.push(*it);
        }
    }
    string ans = "";
    while(!s.empty()){
        ans = ans + s.top();
        s.pop();
    }
    // Reversing the String
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string str;
    getline(cin,str);
    string ans = removeConsecutiveDuplicates(str);
    cout<<"String after Removing Consecutive Duplicates: "<<ans<<endl;
}