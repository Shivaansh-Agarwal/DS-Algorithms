// Stock Buy & Sell
/*
    Given prices of stock for n days. Maximize the Profit.
    Ex:
    I/P => prices[] = {1,5,3,8,12}
                       b s b    s
    O/P => Profit: 4+9 = 13

    I/P => prices[] = {10,5,3}
    O/P => 0

    I/P => prices[] = {1,2,5}
    O/P => 5-1=4
*/
/*
    Local Minima: A number which has both the previous and subsequent elements more than itself.
    Local Maxima: A number which has both the previous and subsequent elements less than itself.
    1. Start a loop from 0 to N-1
    2. Find a local minima
        if NO local minima could be found then Profit = 0
    3. Find the next local maxima
*/
#include<iostream>
using namespace std;
int main(){
    int n; // number of days
    cout<<"Enter the number of days: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the prices: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int localmin, localmax;
    bool minflag = false, maxflag = false;
    int profit=0;
    for(int i=0;i<n;i++){
        if(i==0 && arr[i]<arr[i+1] && !minflag){
            localmin = arr[i];
            minflag = true;
            continue;
        }
        else if(!minflag && i<n-1 && arr[i]<arr[i-1] && arr[i]<arr[i+1]){
            localmin = arr[i];
            minflag = true;
            continue;
        }
        else if(minflag){
            if(i==n-1 && arr[i]>arr[i-1]){
                localmax = arr[i];
                //maxflag = true;
                minflag = false;
                profit = profit + localmax-localmin;
                continue;
            }
            else if(i<n-1 && arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                localmax = arr[i];
                //maxflag = true;
                minflag = false;
                profit = profit + localmax-localmin;
                continue;
            }
        }
    }
    cout<<"Profit: "<<profit<<endl;
    return 0;
}