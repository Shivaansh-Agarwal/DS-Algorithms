/*
    Triplet Sum in Array
    Date: 04/02/2020

    https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/1/?track=SPC-Sorting&batchId=135

    Approach
        => Use 2 Pointers Technique
*/

class TripletSum{
    // function to find the triplet which sum to x
    public static int find3Numbers(int A[], int n, int x) { 
        Arrays.sort(A);
        int ans = 0;
        for(int i=n-1;i>0;i--){
            if(A[i]>x)
                continue;
            int l=0,r=i-1;
            while(l<r){
                int sum = A[l]+A[r]+A[i];
                if(sum==x){
                    ans = 1;
                    break;
                } else if(sum<x){
                    l++;
                } else if(sum>x){
                    r--;
                }
            }
            if(ans==1)
                break;
        }
        return ans;
    }
}