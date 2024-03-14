class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        Map<Integer,Integer>map=new HashMap<>();
        map.put(0,1);
        int sum=0;

        int ans=0;

        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            if(map.containsKey(sum-goal)){
                ans+=map.get(sum-goal);
            }
            if(map.computeIfPresent(sum,(key,prev)->prev+1)==null){
                map.put(sum,1);
            }
        }
        return ans;
    }
}