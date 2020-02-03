/*
    Find Triplets with 0 Sum
    Date: 03/02/2020

    https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1/?track=SPC-Sorting&batchId=135
*/

class Triplet
{
    // Function to check if triplet is present 
    // arr[]: input array
    // n: size of the array
	public boolean findTriplets(int arr[] , int n){
        //add code here.
        Arrays.sort(arr);
        boolean ans = false;
        for(int i=n-1;i>0;i--){
            int l=0,r=i-1;
            while(l<r){
                if(arr[l]+arr[r]+arr[i]==0){
                    ans = true;
                    break;
                } else if(arr[l]+arr[r]+arr[i]<0){
                    l++;
                } else if(arr[l]+arr[r]+arr[i]>0){
                    r--;
                }
            }
            if(ans)
                break;
        }
        return ans;
    }
}