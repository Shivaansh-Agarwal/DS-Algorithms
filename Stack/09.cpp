// Stock Span Problem (Using Stacks)
/*
    Problem Statement:
        Given a list of prices of a single stock for N number of days, find stock span for each day.
        Stock span is defined as a number of consecutive days prior to the current day when the price
        of a stock was less than or equal to the price at current day.
*/
/*
    There can be 2 approaches to solve this problem-
    APPROACH - 1 O(n^2) [INEFFICIENT SOLUTION]
        This uses the concept of nested loops. In this the outer loop works from 0 to n-1
        We pick every element and then run a loop from that position to the beginning of the loop.
        int prices[] = {10,5,2,7,18,15,16,17};
        int stockSpan[n] = {0};
        int count = 0;
        for(int i=0;i<n;i++){
            count = 1;
            for(int j=i-1;j>=0;j--){
                if(arr[j]>=arr[j])
                    count++;
                else
                    break;
            }
            stockSpan[i] = count;
        }

    APPROACH - 2 O(n) [EFFICIENT SOLUTION]
        This approach uses the Stack Data Structure
        In this program this approach is implemented.
        =>  Although because of 2 Loops it seems that it's complexity is O(n^2) BUT,
            if we see closely, we'll notice that we're pushing and popping each element exactly once,
            AND Stack PUSH and POP elements have O(1) Time Complexity.
            So overall we're doing 2n operations and this is O(n) Time Complexity.
 */
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
        /*  
            Whenever an element (price[st.top()]) just before the current element(price[i]) is less than or equal to price[i],
            We pop that element (price[st.top()]) & keep popping until Either the Stack is empty or it is less than the current element.
        */
        while(!st.empty() && price[st.top()] <= price[i])
            st.pop();
        
        // Now we store the span of price[i] element in stockSpan[i]
        if(!st.empty())
            stockSpan[i] = i - st.top();
        else
            stockSpan[i] = i + 1;
        /* 
            The above logic can also be implemented in 1 line as follows
            stockSpan[i] = (!st.empty()) ? (i-st.top()):(i+1);
        */

       // Every element is pushed in the Stack
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