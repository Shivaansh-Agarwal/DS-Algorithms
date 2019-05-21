// Given a String as input, generate it's PowerSet.
/*
	For example,
		I/P-> str = "ABC"
		O/P->
			{"","A","B","C","AB","AC","BC","ABC"}
*/
#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	getline(cin,str); // This can take the whole line including spaces as Input
	//cin>>str; // This takes only 1st word as input and ignores all characters after 1st space.
	int n = str.length();
	int count = 1<<n;; //This will be used to determine the number of subsets, which is 2^n (OR 1<<n)
	for(int i=0;i<count;i++){
		for(int j=0;j<n;j++){
			if((i & (1<<j))>0)
				cout<<str[j];
		}
		cout<<endl;
	}
	return 0;
}
