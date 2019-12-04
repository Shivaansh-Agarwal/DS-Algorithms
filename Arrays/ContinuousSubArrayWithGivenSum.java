import java.io.*;
/*
    PROBLEM: 
    Given an array of integers and a Sum S, find if there's a continuous subarray having sum S.
    Print the beginning and ending indices of the first such occurrence of the subarray.
    If no such subarray exists print -1.

    Input Format
    1st Line: t => number of test cases
    2nd Line: n,s => number of elements in the array & Sum
    3rd Line: arr[] => Array containing all the integers.
*/
class Main{
    void findSubarray(int n, int s, int arr[]){
        int currSum = arr[0];
        int start = 0;
        boolean found = false;
        for(int i=1;i<=n;i++){
            while(currSum>s && start<i-1){
                currSum -= arr[start];
                start++;
            }
            if(currSum==s){
                System.out.println("Subarray found from indices " + (start+1) + " to " + i);
                found=true;
                break;
            }
            if(i<n){
                currSum += arr[i];
            }
        }
        if(!found){
            System.out.println("-1");
        }
    }
    public static void main(String args[]) throws IOException{
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(buff.readLine());
        while(t-->0){
            String line1[] = buff.readLine().trim().split("\\s+");
            int n = Integer.parseInt(line1[0]);
            int s = Integer.parseInt(line1[1]);
            String line2[] = buff.readLine().trim().split("\\s+");
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = Integer.parseInt(line2[i]);
            }
            Main obj1 = new Main();
            obj1.findSubarray(n,s,arr);
        }
    }
}