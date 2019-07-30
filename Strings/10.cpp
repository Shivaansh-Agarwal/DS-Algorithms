/*
    PROBLEM STATEMENT
    Check whether 2 strings are rotations of each other or not.
    I/P: abcde cdeab
    O/P: true

    I/P: prwerst werstkk
    O/P: false

    Here I've used the string.find() method to check whether the substring is present in the string or not.
    Apart from this Any string matching Algorithms could also be used.
*/
#include<iostream>
#include<string>
using namespace std;
bool isRotation(string str1, string str2){
    if(str1.length()!=str2.length())
        return false;
    else{
        str1 = str1 + str1;
        size_t found = str1.find(str2);
        if(found!=string::npos)
            return true;
        else
            return false;
    }
}
int main(){
    string str1, str2;
    cout<<"Enter the 2 strings: ";
    getline(cin,str1);
    getline(cin,str2);
    bool ans = isRotation(str1,str2);
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}