/* 
    PROBLEM STATEMENT
    Find the largest Subarray with 0 Sum.

    I/P: arr[] = {5,3,1,-2,-1,2}
    O/P: Largest Subarray with 0 Sum is of Length 4 and is from indexes 2 to 5

    I/P: arr[] = {5,-5,1,2,3}
    O/P: Largest Subarray with 0 Sum is of Length 2 and is from indexes 0 to 1.

    I/P: arr[] = {7,8,-2,2,0,-1,1,2}
    O/P: Largest Subarray with 0 Sum is of Length 5 and is from indexes 2 to 6.

    I/P: arr[] = {-1,1,-1,1}
    O/P: Largest Subarray with 0 Sum is of Length 5 and is from indexes 0 to 3.
*/
#include <iostream>
#include <unordered_map>
using namespace std;
void largestSubarrayWithZeroSum(int *arr, int n){
    unordered_map<int, int> umap;
    int preSum = 0;
    int length = 0, l_index, r_index;
    umap[0] = 0;
    for (int i = 0; i < n; i++){
        preSum += arr[i];
        if (umap.find(preSum) != umap.end()){
            if (preSum == 0){
                // When subarray starts from beginning
                l_index = 0;
                r_index = i;
                length = r_index - l_index + 1;
                continue;
            }
            else if (length == 0){
                l_index = umap.find(preSum)->second + 1;
                r_index = i;
                length = r_index - l_index + 1;
                continue;
            }
            else{
                int temp1 = umap.find(preSum)->second + 1;
                if ((i - temp1 + 1) >= length){
                    l_index = temp1;
                    r_index = i;
                    length = r_index - l_index + 1;
                    continue;
                }
            }
        }
        umap[preSum] = i;
    }
    if(length!=0)
        cout<<"Largest Subarray with 0 Sum is of Length "<<length<<" and is from indexes "<<l_index<<" to "<<r_index;
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
    largestSubarrayWithZeroSum(arr, n);
    return 0;
}