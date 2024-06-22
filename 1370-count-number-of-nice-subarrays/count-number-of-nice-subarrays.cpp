class Solution {
    using ll=long long;
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }

    ll fun(vector<int>&nums,int k){
        int n=nums.size(),i=0,j=0;
        ll ans=0,cnt=0;

        while(j<n){
            if(nums[j]%2!=0)cnt++;
            while(cnt>k){
                if(nums[i]%2!=0)cnt--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }

};