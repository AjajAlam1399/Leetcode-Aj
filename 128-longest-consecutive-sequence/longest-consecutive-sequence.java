class Solution {
    public int longestConsecutive(int[] nums) {
        int ans=0;
        int n=nums.length;

        Map<Integer,Integer> map = new HashMap<>();

        for(int i=0;i<n;i++){
            map.put(nums[i],1);
        }

        for(int i=0;i<n;i++){
            if(map.containsKey(nums[i]-1))continue;
            int currNum=nums[i];
            int currcnt=0;

            while(map.containsKey(currNum)){
                currNum++;
                currcnt++;
            }
            ans=Math.max(ans,currcnt);
            if(currcnt>n/2)break;
        }

        return ans;
    }
}