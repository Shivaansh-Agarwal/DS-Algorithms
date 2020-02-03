/*
	Count possible triangles (GeeksForGeeks)
	Date: 03/02/2020

	Practice: https://practice.geeksforgeeks.org/problems/count-possible-triangles/1/?track=SPC-Sorting&batchId=135
	Solution: https://www.geeksforgeeks.org/find-number-of-triangles-possible/

	Problem: Given an unsorted array arr of positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles.

		I/P:
			3 5 4			6 4 9 7 8
		O/P:
			1				10

	Concept of 2 pointers is to be used in order to solve this question
*/

class Count_possible_triangle
{
    // Function to find number of triangles that can be formed
    // arr[]: input array
    // n: size of array
    static long findNumberOfTriangles(int arr[], int n){
        // add your code here
        Arrays.sort(arr);
        long count=0;
        for(int i=n-1;i>=1;i--){
            int l=0,r=i-1;
            while(l<r){
                if((arr[l]+arr[r])>arr[i]){
                    count+=(long)(r-l);
                    r--;
                } else {
                    l++;
                }
            }
        }
        return count;
    }
}