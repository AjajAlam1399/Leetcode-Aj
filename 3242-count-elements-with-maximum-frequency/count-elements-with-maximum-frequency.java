class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer,Integer>map=new HashMap<>();
        int n=nums.length;

        for(int i=0;i<n;i++){
            if(map.containsKey(nums[i])){
                map.put(nums[i],map.get(nums[i])+1);
            }
            else{
                map.put(nums[i],1);
            }
        }
        int maxval=Integer.MIN_VALUE;
        int cnt=0;
        for(Map.Entry<Integer,Integer>entry:map.entrySet()){
            maxval=Math.max(maxval,entry.getValue());
        }
        for(Map.Entry<Integer,Integer>entry:map.entrySet()){
            if(entry.getValue()==maxval){
                cnt+=entry.getValue();
            }
        }
        return cnt;
    }
}