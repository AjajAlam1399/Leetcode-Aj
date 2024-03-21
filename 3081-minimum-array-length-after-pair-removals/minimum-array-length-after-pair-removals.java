class Solution {
    public int minLengthAfterRemovals(List<Integer> nums) {
        PriorityQueue<Integer>pq=new PriorityQueue<>((a,b)->b-a);
        int n=nums.size();
        int i=0,cnt=1;

        while(i<n){
            while(i+1<n && Integer.compare(nums.get(i),nums.get(i+1))==0){
                i++;
                cnt++;
            }
            pq.offer(cnt);
            cnt=1;
            i++;
        }
        System.out.print(pq.peek());
        while(pq.size()>1){
            int a=pq.poll()-1;
            int b=pq.poll()-1;

            if(a>0){
                pq.offer(a);
            }
            if(b>0){
                pq.offer(b);
            }
        }
        return pq.size()>=1?pq.peek():0;
    }
}