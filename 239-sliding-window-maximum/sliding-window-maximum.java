class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n=nums.length;

        List<Integer> ls = new ArrayList<>();
        ArrayDeque<Integer> dq = new ArrayDeque<>();

        for(int i=0;i<n;i++){
            while(!dq.isEmpty() && dq.peekFirst()<=(i-k)){
                dq.pollFirst();
            }
            while(!dq.isEmpty() && nums[dq.peekLast()]<=nums[i]){
                dq.pollLast();
            }
            dq.offerLast(i);

            if(i+1>=k){
                ls.add(nums[dq.peekFirst()]);
            }
        }

        return ls.stream().mapToInt(num->(int)num).toArray();
    }
}