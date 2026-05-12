class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points,(a,b)->{
            if(Integer.compare(a[1],b[1])==0){
                return Integer.compare(a[0],b[0]);
            }
            return Integer.compare(a[1],b[1]);
        });
        // for(int i=0;i<points.length;i++){
        //     System.out.println(points[i][0] + ","+points[i][1]);
        // }
        int ans=1;
        int n=points.length;
        int currMaxW=points[0][1];
        int ind=1;

        while(ind<n){
            int currInd=ind;
            while(currInd<n && points[currInd][0]<=currMaxW){
                currInd++;
            }
            if(currInd<n){
                ans++;
                currMaxW=points[currInd][1];
            }
            ind=currInd+1;
        }

        return ans;
    }
}