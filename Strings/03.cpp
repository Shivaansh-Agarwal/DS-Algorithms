/*
    PROBLEM STATEMENT
    Given a String, find the first non-repeating Character.

    I/P: s="shivaansh"
    O/P: i

    I/P: s="agarwal"
    O/P: g
*/
//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

/** 
 * Returns -1 if there is No Non Repeating Character.
 * else Returns the index of the character in the string which is the first Non-Repeating Element.
**/
int getFirstNonRepeatingCharacter(string str){
    int count[256] = {0};
    int ans = -1;
    for(int i=0;i<str.length();i++)
        count[str[i]]+=1;
    for(int i=0;i<str.length();i++){
        if(count[str[i]]==1){
            ans = i;
            break;
        }
    }
    return ans;
}
int main(){
    string str;
    cout<<"Enter a String: ";
    getline(cin,str);
    int index = getFirstNonRepeatingCharacter(str);
    if(index==-1)
        cout<<"There is no Repeating Element";
    else
        cout<<"First Non-Repeating Element: "<<str[index];
    return 0;
}