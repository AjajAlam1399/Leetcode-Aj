class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer>pq=new PriorityQueue<>();
        int n=heights.length;
        int diff;
        for(int i=0;i<n-1;i++){
            diff=heights[i+1]-heights[i];
            if(diff>0){
                pq.offer(diff);
                if(pq.size()>ladders){
                    diff=pq.poll();
                    bricks-=diff;
                    if(bricks<0){
                        return i;
                    }
                }
            }
        }
        return n-1;
    }
}