/*
    PROBLEM STATEMENT
    Anagram Search
    Given two strings, suppose txt="geeksforgeeks", pattern="rof"
    Find whether the permutation of this pattern is present in txt string or not.
    Hence since a permutation is present, answer is YES.
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool anagramSearch(string txt, string pat){
    int n = txt.length();
    int m = pat.length();
    int count_pat[256] = {0};
    int count_txt[256] = {0};
    bool ans;
    for(int i=0;i<m;i++){
        count_pat[pat[i]]++;
        count_txt[txt[i]]++;
    }
    ans = true;
    for(int i=0;i<256;i++){
        // This loop has time complexity of O(1) since the number of iterations are fixed.
        if(count_pat[i]!=count_txt[i]){
            ans = false;
            break;
        }
    }
    if(ans){
        cout<<"Anagram starts from index: 0"<<" ";
        return ans;
    }
    for(int i=1;i<n-m;i++){
        count_txt[txt[i-1]] -=1 ;
        count_txt[txt[i+m-1]]+=1;
        ans = true;
        for(int j=0;j<256;j++){
            if(count_pat[j]!=count_txt[j]){
                ans = false;
                break;
            } 
        }
        if(ans){
            cout<<"Anagram starts from index: "<<i<<" ";
            break;
        }
        else
            continue;
    }
    return ans;
}
int main(){
    string txt,pattern;
    cout<<"Enter text String: ";
    getline(cin,txt);
    cout<<"Enter pattern String: ";
    getline(cin,pattern);
    bool ans = anagramSearch(txt,pattern);
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}