class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer,Integer>map=new HashMap<>();
        int diff=0;
        map.put(0,-1);
        int ans=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1){
                diff++;
            }
            else{
                diff--;
            }
            if(map.containsKey(diff)){
                ans=Math.max(ans,i-map.get(diff));
            }
            else{
                map.put(diff,i);
            }
        }

        return ans;
    }
}