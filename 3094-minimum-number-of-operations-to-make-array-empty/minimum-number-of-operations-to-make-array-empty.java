class Solution {
    public int minOperations(int[] nums) {
         Map<Integer,Integer>map=new HashMap<>();
        int n=nums.length;

        for(int i=0;i<n;i++){
            if(map.containsKey(nums[i])){
                map.replace(nums[i],map.get(nums[i])+1);
            }
            else{
                map.put(nums[i],1);
            }
        }
        int ans=0;

        for(Map.Entry<Integer,Integer>it:map.entrySet()){
            int val=it.getValue();
            if(val==1)return -1;
            if(val%3==0){
                ans+=val/3;
            }
            else if(val%3==1){
                ans+=val/3;
                ans--;
                ans+=2;
            }
            else if (val%3==2){
                ans+=val/3;
                ans++;
            }
        }
        return ans;
    }
}