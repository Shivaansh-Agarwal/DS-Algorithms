/*
    PROBLEM STATEMENT
    Given 2 strings, check if they're anagrams of each others.
    (HINT: Anagram means if the frequency of characters in both strings is same)

    I/P: s1="gfg"       I/P: s1 = "gfgg"        I/P: s1="fff"
         s2="ggf"            s2 = "gfg"              s2="trf"
    O/P: YES            O/P: NO                 O/P: NO
*/
#include<iostream>
#include<string>
using namespace std;

bool isAnagram(string s1,string s2){
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1!=len2)
        return false;
    int count1[256] = {0};
    int count2[256] = {0};
    for(int i=0;i<len1;i++){
        count1[s1[i]]+=1;
        count2[s2[i]]+=1;
    }
    bool ans = true;
    for(int i=0;i<256;i++){
        if(count1[i]==count2[i])
            continue;
        else{
            ans = false;
            break;
        }
    }
    return ans;
}

int main(){
    string s1,s2;
    cout<<"Enter String 1: ";
    getline(cin,s1);
    cout<<"Enter String 2: ";
    getline(cin,s2);
    if(isAnagram(s1,s2))
        cout<<"YES the two strings are anagrams of each other."<<endl;
    else
        cout<<"NO the two strings are not anagrams"<<endl;
    return 0;
}