class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->{return Integer.compare(a,b);});

        for(int i=0;i<nums.length;i++){
            if(pq.size()<k){
                pq.offer(nums[i]);
            }
            else{
                if(pq.peek()<nums[i]){
                    pq.poll();
                    pq.offer(nums[i]);
                }
            }
        }

        return pq.poll();
    }
}