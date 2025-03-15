class Solution {
    using ll=long long;
public:
    int minCapability(vector<int>& nums, int k) {
        ll s=1e9+1,e=0,n=nums.size();

        for(ll i=0;i<n;i++){
            s=min(s,(ll)nums[i]);
            e=max(e,(ll)nums[i]);
        }
        int ans=e;

        while(s<=e){
            ll mid=(s+e)/2;
            if(check(nums,mid,k)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    bool check(vector<int>&nums,int ans,int k){
        int s=0,n=nums.size();
        int cnt=0;
        while(s<n){
            if(nums[s]<=ans){
                s+=2;
                cnt++;
            }
            else{
                s++;
            }
        }
        return cnt>=k;
    }
};