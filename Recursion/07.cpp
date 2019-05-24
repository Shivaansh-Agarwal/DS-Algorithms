//Print all substrings of a given String
/*
    I/P = "ABC"
    O/P = {"", "A", "B", "C", "AB", "AC", "BC", "ABC"}
*/
// This problem has also been solved using Bitwise Operations
#include<iostream>
#include<string>
using namespace std;
void printAllSubstrings(string str, int index=0, string currsub=""){
    int n = str.length();
    if(index==n){
        cout<<currsub<<endl;
        return;
    }
    printAllSubstrings(str, index+1, currsub);
    printAllSubstrings(str, index+1, currsub+str[index]);
}
int main(){
    string str;
    getline(cin,str);
    printAllSubstrings(str);
    return 0;
}
