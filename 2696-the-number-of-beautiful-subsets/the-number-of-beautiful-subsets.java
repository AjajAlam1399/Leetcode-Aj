class Solution {
    public int beautifulSubsets(int[] nums, int k) {
        int n=nums.length;
        int[][]dp=new int[n][(2<<n)+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return fun(n-1,0,nums,k,dp);
    }

    int fun(int ind,int bitmask,int[]nums,int k,int[][]dp){
        if(ind==-1){
            return bitmask==0?0:1;
        }
        if(dp[ind][bitmask]!=-1){
            return dp[ind+1][bitmask];
        }
        int not_taken=fun(ind-1,bitmask,nums,k,dp);
        int taken=0;
        if(bitmask==0){
            taken=fun(ind-1,(bitmask|(1<<ind)),nums,k,dp);
        }
        else{
            int maskvalue=bitmask;
            int i=0;
            boolean flag=false;
            while(maskvalue!=0){
                int bit=((maskvalue)&(1));
                if(bit==1){
                    if(Math.abs(nums[ind]-nums[i])==k){
                        flag=true;
                        break;
                    }
                }
                maskvalue=maskvalue>>1;
                i++;
            }
            if(!flag){
                taken=fun(ind-1,(bitmask|(1<<ind)),nums,k,dp);
            }
        }
        return dp[ind][bitmask]=taken+not_taken;
    }
}