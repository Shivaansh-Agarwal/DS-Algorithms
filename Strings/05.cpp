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
    //First I'll make the count array of string 'pat'
    int n = txt.length();
    int m = pat.length();
    int count_pat[256] = {0};
    int count_txt[256] = {0};
    bool ans = false;
    for(int i=0;i<m;i++)
        count_pat[pat[i]]++;
    for(int i=0;i<n-m;i++){
        std::fill_n(count_txt, 256, 0); // #include<algorithm>
        for(int j=i;j<i+m;j++){
            // This loop will be run m times to make the count array of `m` characters in `txt` String.
            count_txt[txt[j]]++;
        }
        ans = true;
        for(int j=0;j<256;j++){
            if(count_pat[j]!=count_txt[j]){
                ans = false;
                break;
            }
        }
        // if pattern is found in the text then ans=true else false;
        if(ans)
            break;
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