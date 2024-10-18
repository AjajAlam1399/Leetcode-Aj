class Solution {
    using ll=long long;
public:
    int countMaxOrSubsets(vector<int>& nums) {
        ll maxOr=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            maxOr|=nums[i];
        }
        ll ans=0;
        fun(0,0,maxOr,nums,ans);
        return ans;
    }

    void fun(int ind,int currOr,ll &maxOr,vector<int>& nums,ll &ans){
        if(ind==nums.size()){
            ans+=currOr==maxOr;
            return ;
        }
        fun(ind+1,currOr,maxOr,nums,ans);
        fun(ind+1,currOr|nums[ind],maxOr,nums,ans);
    }
};