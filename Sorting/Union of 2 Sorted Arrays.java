/*
    Union of 2 Sorted Arrays

        https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays/1/?track=SPC-Sorting&batchId=135
        Date: 01/02/2020

        Used Merge Sort to print the Union of 2 Arrays
*/

//arr1,arr2 : the arrays
// n, m: size of arrays
class Union{
    static void findUnion(int arr1[], int arr2[], int n, int m){
        int i=0,j=0,prev=-1;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                if(arr1[i]!=prev){
                    prev = arr1[i];
                    System.out.print(arr1[i]+" ");
                }
                i++;
            } else if(arr1[i]>arr2[j]){
                if(arr2[j]!=prev){
                    prev = arr2[j];
                    System.out.print(arr2[j]+" ");
                }
                j++;
            } else if(arr1[i]==arr2[j]){
                if(arr1[i]!=prev){
                    prev = arr1[i];
                    System.out.print(arr1[i]+" ");
                }
                i++;
                j++;
            }
        }
        while(i<n){
            if(arr1[i]!=prev){
                prev = arr1[i];
                System.out.print(arr1[i] +" ");
            }
            i++;
        }
        while(j<m){
            if(arr2[j]!=prev){
                prev = arr2[j];
                System.out.print(arr2[j] +" ");
            }
            j++;
        }
    }
}