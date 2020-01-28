/*
	Quick Sort
	Date: 28/01/2020
*/

import java.lang.*;
import java.io.*;		//For BufferedReader
import java.util.*; 	//For StringTokenizer

public class GFG {
	public static void main(String args[]) throws IOException{
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(buff.readLine());
		StringTokenizer line = new StringTokenizer(buff.readLine());
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = Integer.parseInt(line.nextToken());
		quickSort(arr,0,n-1);
		printArray(arr,n);
	}

	public static void quickSort(int arr[], int left, int right){
		if(left<right){
			int p = partition(arr,left,right);
			quickSort(arr,left,p-1);
			quickSort(arr,p+1,right);
		}
	}

	public static int partition(int arr[], int left, int right){
		int pivot = arr[right];
		int i = left-1;
		for(int j=left;j<right;j++){
			if(arr[j]<=pivot){
				i++;
				swap(arr,i,j);
			}
		}
		swap(arr,i+1,right);
		return i+1;
	}

	public static void swap(int arr[], int i, int j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	public static void printArray(int arr[], int n){
	    for(int i=0;i<n;i++)
	        System.out.print(arr[i] +" ");
	}
}