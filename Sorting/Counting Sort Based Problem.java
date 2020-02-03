/*
    Problem based on Counting Sort
    Date: 03/02/2020

    https://practice.geeksforgeeks.org/problems/counting-sort/1/?track=SPC-Sorting&batchId=135  
*/
class GfG{
    // Function to do count sort
    // seq[]: input array
    public static void countSort(char seq[]){
        // add your code here
        int count[] = new int[26];
        for(int i=0;i<seq.length;i++){
            count[seq[i]-97]++;
        }
        //String ans = "";
        int k=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<count[i];j++){
                seq[k++] = (char)(i+97);
                //ans += (char)(i+97);
            }
        }
        //System.out.println(ans);
    }
}