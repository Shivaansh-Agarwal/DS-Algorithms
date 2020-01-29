/*
    Inversion Count of an Array

        https://practice.geeksforgeeks.org/problems/inversion-of-array/1/?track=SPC-Sorting&batchId=135
        Date: 29/01/2020

        Inversion Count: How far or close an array is from being sorted. 
        The inversion Count of a sorted array is 0, 
        whereas of an array in reverse sorted order is maximum.

        I/P:
            5                               3                               5
            2 4 1 3 5                       10 10 10                        1 2 3 4 5
        O/P:
            3                               0                               0
        Explanation:
            (2,1), (4,1), (4,3)

    Approach
        This problem could be solved using a brute force approach but that will take O(n^2) time.
        So in this question I've used MERGE SORT to figure out the inversion count.
        So as we know that merge sort has 2 subroutines i.e.
            1. split suroutine (mergeSort())
                It keeps on splitting the array in 2 parts until they become single elements i.e. (our base condition of left<right fails)
            2. merge subrouitne (merge()) 
                It merges the 2 sorted arrays
                It is in this subroutine that we've to write our logic.
                So what happens is this method compares the elements of L[] and R[] arrays one by one.
                So whenever L[i] > R[j], we'll count the number of elements in L[i] that are greater than R[j] and store it in out 'count' variable. 
                We can do this calculating the number of elements from i to n1
                Therefore
                count += n1-i
*/

import java.util.*;
import java.io.*;
import java.lang.*;

// Class containing the main method.
class Sorting {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        while(t-- > 0) {
            long n = sc.nextLong();
            long arr[] = new long[(int)n];
            for(long i = 0; i < n; i++)
                arr[(int)i] = sc.nextLong();
            System.out.println(new Inversion_of_Array().inversionCount(arr, n));
        }
    }
}

class Inversion_of_Array {
    static long count=0;
    
    /** Function to count the number of inversions
     *  arr[]: input array
     *  n: size of array
     */ 
    static long inversionCount(long arr[], long n)
    {
        // add your code here
        Inversion_of_Array.count = 0;
        mergeSort(arr,0,(int)n-1);
        return Inversion_of_Array.count;
    }
    
    static void mergeSort(long arr[], int left, int right){
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);
            merge(arr,left,mid,right);
        }
    }
    
    static void merge(long arr[], int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right-mid;
        
        long L[] = new long[n1];
        long R[] = new long[n2];
        
        for(int i=0;i<n1;i++)
            L[i] = arr[left+i];
        for(int j=0;j<n2;j++)
            R[j] = arr[mid+1+j];
            
        int i=0,j=0,k=left;
        
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
                Inversion_of_Array.count += n1-i;
            }
            k++;
        }
        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}