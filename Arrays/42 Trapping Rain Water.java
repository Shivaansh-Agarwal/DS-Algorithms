/*
    Leetcode
    42. Trapping Rain Water
    https://leetcode.com/problems/trapping-rain-water/
*/
class Solution {
    public int trap(int[] height) {
        /*
            1. Water can be filled only on indices where height on that index is smaller some index on both it's left and right.
            2. Hence Water cannot be filled on the extreme left or extreme right, since there is no height greater than it on it's left and on it's right respectively.
            3. If somehow for every index we get to know what is the maximum height before it and after it we can tell whether water will get filled in it or not. Therefore we'll create 2 array,s 1 containing the maximum height on it's left and the other containing the maximum height on the left of it.
        */
        int leftMaxTillHere = -1;
        int rightMaxTillHere = -1;
        int n = height.length;
        int left[] = new int[n];
        int right[] = new int[n];
        if(n==0)
            return 0;
        left[0] = leftMaxTillHere;
        for(int i=1;i<n;i++){
            leftMaxTillHere = Math.max(leftMaxTillHere, height[i-1]);
            left[i] = leftMaxTillHere;
        }
        
        right[n-1] = rightMaxTillHere;
        for(int i=n-2;i>=0;i--){
            rightMaxTillHere = Math.max(rightMaxTillHere, height[i+1]);
            right[i] = rightMaxTillHere;
        }
        //System.out.println(Arrays.toString(left));
        //System.out.println(Arrays.toString(right));
        int trappedWater = 0;
        for(int i=1;i<n-1;i++){
            if(height[i]<left[i] && height[i]<right[i])
                trappedWater += (Math.min(left[i], right[i]) - height[i]);
        }
        return trappedWater;
    }
}