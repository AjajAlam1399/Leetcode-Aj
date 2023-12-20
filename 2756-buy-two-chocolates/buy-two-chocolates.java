class Solution {
    public int buyChoco(int[] prices, int money) {
         PriorityQueue<Integer>pq=new PriorityQueue<>((a,b)->b-a);

        for(int i=0;i<prices.length;i++){
            if(pq.size()<2){
                pq.offer(prices[i]);
            }
            else{
                if(pq.peek()>prices[i]){
                    pq.poll();
                    pq.offer(prices[i]);
                }
            }
        }
        int sum=0;
        sum+=pq.peek();
        pq.poll();
       sum+= pq.peek();
        return sum<=money?money-sum:money;
    }
}