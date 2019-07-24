/*
    PROBLEM STATEMENT
    Given a String, find first repeating character in it.

    I/P: s1 = "shivaansh"       s1="geeksforgeeks"      s1="abcbc"
    O/P: 's'                    'g'                     'b'
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int firstRepeatingCharacter(string s){
    int count[256];
    int res = INT_MAX;// This variable will be used to store the index of the repeating characters and eventually contain the first repeating character's index
    std::fill_n(count, 256, -1); // #include<algorithm>
    for(int i=0;i<s.length();i++){
        if(count[s[i]]==-1)
            count[s[i]] = i;
        else
            res = min(res,count[s[i]]);
    }
    //if any character does not repeat in the string
    if(res>s.length())
        res = -1;
    return res;
}

int main(){
    string s;
    cout<<"Enter String: ";
    getline(cin,s);
    int res = firstRepeatingCharacter(s);
    if(res==-1)
        cout<<"No element is repeating"<<endl;
    else
        cout<<"First Repeating Element: "<<s[res]<<endl;
    return 0;
}