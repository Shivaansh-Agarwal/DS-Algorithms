/*
    Closest 0's, 1's and 2's
    Date: 03/02/2020

    https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/1/?track=SPC-Sorting&batchId=135

    It also uses the same concept of 3-way partitioning.
*/

class Sort012
{
    // Function to segregate 0s, 1s and 2s
    // A[]: input array
    // n: size of array
    public static void segragate012(int A[], int n){
        int j=0;
        for(int i=0;i<n;i++){
            if(A[i]<1){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                j++;
            }
        }
        j=n-1;
        for(int i=n-1;i>=0;i--){
            if(A[i]>1){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                j--;
            }
        }
    }
}