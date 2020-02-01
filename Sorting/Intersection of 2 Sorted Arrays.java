/*
    Intersection of 2 Sorted Arrays

        https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-array/1/?track=SPC-Sorting&batchId=135
        Date: 01/02/2020

        Used merge() subroutine of Merge Sort with some slight modifications to Find the Intersection of 2 Sorted Arrays.
*/

class Intersection
{
    /* Function prints Intersection of arr1[] and arr2[] 
    n is the number of elements in arr1[] 
    m is the number of elements in arr2[] */
    static void printIntersection(int arr1[], int arr2[], int n, int m) {
        int i=0,j=0,prev=-1;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                i++;
            } else if(arr1[i] > arr2[j]){
                j++;
            } else if(arr1[i]==arr2[j]){
                if(arr1[i]!=prev){
                    prev = arr1[i];
                    System.out.print(arr1[i] + " ");
                }
                i++;
                j++;
            }
        }
    }
}