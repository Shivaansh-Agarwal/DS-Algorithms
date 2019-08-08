/* 
    PROBLEM STATEMENT
    Smallest Subarray with 0 Sum

    I/P: arr[] = {4 -1 -2 3 -4}
    O/P: Smallest Subarray with 0 Sum is of Length 3 and is from indexes 1 to 3
*/
#include<iostream>
#include<unordered_map>
using namespace std;
void smallestSubarrayWithZeroSum(int *arr, int n){
    unordered_map<int,int> umap;
    int preSum = 0;
    int l_index,r_index,length=0;
    umap[0] = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            // if 0 is present in the array
            if(length==0){
                length = 1;
                l_index = 0;
                r_index = 0;
                cout<<"Smallest Subarray with 0 Sum is of Length "<<length<<" and is from indexes "<<l_index<<" to "<<r_index;
                return;
            }
        }
        preSum += arr[i];
        if(umap.find(preSum)!=umap.end()){
            if(preSum==0 && length==0){
                // When subarray starts from index 0 and it's the first subArray to be found.
                l_index = 0;
                r_index = i;
                length = r_index-l_index+1;
                continue;
            }
            else if(preSum==0){
                // When subarray is found but it isn't the first subArray to be found.
                if((i+1)<length){
                    // if length of this subarray is less than previous smaller subarray
                    l_index = 0;
                    r_index = i;
                    length = r_index-l_index+1;
                    continue;
                }
            }
            else if(length==0){
                // When first Subarray is found which doesn't begin from index 0.
                l_index = umap.find(preSum)->second+1;
                r_index = i;
                length = r_index-l_index+1;
                continue;
            }
            else{
                int temp1 = umap.find(preSum)->second+1;
                if((i-temp1+1)<length){
                    l_index = temp1;
                    r_index = i;
                    length = r_index-l_index+1;
                    continue;
                }
            }
        }//if element present in Map condition end
        umap[preSum] = i;
    }//for loop end
    if(length!=0)
        cout<<"Smallest Subarray with 0 Sum is of Length "<<length<<" and is from indexes "<<l_index<<" to "<<r_index;
    else
        cout<<-1;
}
int main()
{
    int n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    smallestSubarrayWithZeroSum(arr, n);
    return 0;
}