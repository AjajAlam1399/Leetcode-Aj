class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>greater(n,0),smaller(n,INT_MAX);
        int mV=0;
        for(int i=0;i<n;i++){
            mV=max(mV,nums[i]);
            greater[i]=mV;
        }
        mV=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mV=min(mV,nums[i]);
            smaller[i]=mV;
        }

        vector<int>ans(n,0);
        ans[n-1]=greater[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=greater[i];
            if(greater[i]>smaller[i+1]){
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
};