class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        int ans=0;
        Arrays.sort(points,(a,b)->a[0]-b[0]);
        for(int i=1;i<points.length;i++){
            int p1=points[i-1][0];
            int p2=points[i][0];
            ans=Math.max(ans,p2-p1);
        }
        return ans;
    }
}