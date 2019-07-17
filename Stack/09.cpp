// Stock Span Problem
#include<iostream>
#include<stack>
using namespace std;

void printStockSpan(int stockSpan[], int n){
    for(int i=0;i<n;i++)
        cout<<stockSpan[i]<<" ";
}

void calculateStockSpan(int price[], int n){
    stack<int> st;
    int stockSpan[n]; // This array will be used to Store the StockSpan of all elements given in the array price[]
    stockSpan[0] = 1; // For the first element the StockSpan will always be 1
    st.push(0); // We pushed the index of the first element of the array price[].

    for(int i=1;i<n;i++){
        while(!st.empty() && price[st.top()] <= price[i])
            st.pop();
        
        if(!st.empty())
            stockSpan[i] = i - st.top();
        else
            stockSpan[i] = i + 1;
        /* 
            The above logic can also be implemented in 1 line as follows
            stockSpan[i] = (!st.empty()) ? (i-st.top()):(i+1);
        */

       st.push(i);
    }
    printStockSpan(stockSpan,n);
}
int main(){
    int price[] = {10,5,2,7,18,15,16,17};
    int n = sizeof(price)/sizeof(int);
    calculateStockSpan(price,n);
    return 0;
}