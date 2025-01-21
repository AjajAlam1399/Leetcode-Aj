class Solution {
    using ll=long long;
public:
    int splitArray(vector<int>& nums, int k) {
        ll left=0,right=0;
        for(auto num:nums)right+=num;

        while(left<right){
            ll mid=left+(right-left)/2;
            bool cond=check(mid,nums,k);
            if(cond){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }

    bool check(int currAns,vector<int>&nums,int &k){
        int cnt=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>currAns)return false;
            if(sum+nums[i]>currAns){
                cnt++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return cnt<=k;
    }
};