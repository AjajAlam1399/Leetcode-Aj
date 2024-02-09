class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>path(n,0);
        int maxlen=1;
        int lastind=0;
        for(int i=0;i<n;i++){
            path[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    path[i]=j;
                }
            }
            if(dp[i]>=maxlen){
                maxlen=dp[i];
                lastind=i;
            }
        }
        vector<int>ans(maxlen,0);
        // maxlen--;
        // ans[maxlen]=nums[lastind];
        maxlen--;
        while(lastind!=path[lastind]){
            ans[maxlen]=nums[lastind];
            maxlen--;
            lastind=path[lastind];
        }
        ans[0]=nums[lastind];
        return ans;
    }
};