class Solution {
    public int longestConsecutive(int[] nums) {
        int ans=0;
        int n=nums.length;

        Set<Integer> map = new HashSet<>();

        for(int i=0;i<n;i++){
            map.add(nums[i]);
        }

        for(int i=0;i<n;i++){
            if(map.contains(nums[i]-1))continue;
            int currNum=nums[i];
            int currcnt=0;

            while(map.contains(currNum)){
                currNum++;
                currcnt++;
            }
            ans=Math.max(ans,currcnt);
            if(currcnt>n/2)break;
        }

        return ans;
    }
}