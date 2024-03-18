class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points,(a,b)->{
            return Integer.compare(a[1], b[1]);
        });
        
        int cnt=1;
        long end=points[0][1];
        for(int i=1;i<points.length;i++){
            if((long)points[i][0]>end){
                cnt++;
                end=points[i][1];
            }
        }
        return cnt;
    }
}