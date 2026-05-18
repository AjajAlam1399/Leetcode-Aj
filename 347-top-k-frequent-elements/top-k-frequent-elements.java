class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        
        Map<Integer,Integer> map = new HashMap<>();

        for(int i=0;i<nums.length;i++){
            map.compute(nums[i],(id,val)->{
                if(val==null)val=0;

                return val+1;
            });
        }

        PriorityQueue<int []> pq = new PriorityQueue<>((a,b)->{
            return Integer.compare(a[1],b[1]);
        });

        for(Map.Entry<Integer,Integer> m : map.entrySet()){
            if(pq.size()<k){
                pq.offer(new int[]{m.getKey(),m.getValue()});
            }
            else if(pq.peek()[1]<m.getValue()){
                pq.poll();
                pq.offer(new int[]{m.getKey(),m.getValue()});
            }
        }

        int []ans = new int[k];
        int ind=0;
        
        while(!pq.isEmpty()){
            ans[ind++]=pq.peek()[0];
            pq.poll();
        }

        return ans;
    }
}