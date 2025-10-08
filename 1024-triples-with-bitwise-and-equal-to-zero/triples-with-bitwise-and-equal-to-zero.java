class Solution {
    int dp[][];
    public int countTriplets(int[] nums) {
        dp=new int[4][(1<<16)+5];

        for(int i=0;i<4;i++){
            Arrays.fill(dp[i],-1);
        }

        return fun(0,-1,nums);
    }

    int fun(int ind,int val,int [] nums){

        if(ind==3){
            return val==0?1:0;
        }

        if(dp[ind][val+1]!=-1)return dp[ind][val+1];

        int ans=0;

        for(int i=0;i<nums.length;i++){
            if(val==-1){
                ans+=fun(ind+1,nums[i],nums);
            }
            else{
                ans+=fun(ind+1,val&nums[i],nums);
            }
        }

        return dp[ind][val+1]= ans;
    }
}