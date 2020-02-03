/*
    Three way partitioning
    Date: 03/02/2020

    https://practice.geeksforgeeks.org/problems/three-way-partitioning/1/?track=SPC-Sorting&batchId=135

    Also Read-
    Quick Sort
    Dutch National Flag Problem
*/

class GfG{
	public ArrayList<Integer> threeWayPartition(ArrayList<Integer> A, int a, int b){
	    int n = A.size();
	    int j=0,temp=0;
        for(int i=0;i<n;i++){
            if(A.get(i)<a){
                temp = A.get(i);
                A.set(i,A.get(j));
                A.set(j,temp);
                j++;
            }
        }
        j=n-1;
        for(int i=n-1;i>=0;i--){
            if(A.get(i)>b){
                temp = A.get(i);
                A.set(i,A.get(j));
                A.set(j,temp);
                j--;
            }
        }
        // for(Integer num: A){
        //     System.out.print(num + " ");
        // }
        return A;
    }
}