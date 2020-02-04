/*
    Sort by Absolute Difference
    Date: 04/02/2020

    https://practice.geeksforgeeks.org/problems/sort-by-absolute-difference/1/?track=SPC-Sorting&batchId=135

    This question can be helpful in solving following doubts/problems too:
        How to sort an array based on another array?
            => By making an array of objects containing both the arrays and sort using Comparator
        How to use comparator to sort an array?
*/

class Pair {
    int x;
    int y;
    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}
class SortABS
{
    // here k is the value with which we have to 
    // compute absolute difference
    // length of array can be computed as arr.length
    static void sortABS(int arr[], int n,int k){
        // add your code here
        Pair p[] = new Pair[n];
        for(int i=0;i<n;i++){
            p[i] = new Pair(Math.abs(arr[i]-k),arr[i]);
        }
        Arrays.sort(p,new Comparator<Pair>(){
            @Override
            public int compare(Pair a, Pair b){
                return a.x-b.x;
            }
        });
        for(int i=0;i<n;i++){
            System.out.print(p[i].y + " ");
        }
    }
}