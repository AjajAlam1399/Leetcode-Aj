class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int [] rightMax = new int[n];
        rightMax[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--){
            rightMax[i] = Math.max(height[i],rightMax[i+1]);
        }
        int currMax=0;
        int ans=0;
        for(int i=0;i<n;i++){
            currMax=Math.max(currMax,height[i]);
            int overMin = Math.min(currMax,rightMax[i]);
            if(overMin>height[i]){
                ans+=overMin-height[i];
            }
        }

        return ans;
    }
}