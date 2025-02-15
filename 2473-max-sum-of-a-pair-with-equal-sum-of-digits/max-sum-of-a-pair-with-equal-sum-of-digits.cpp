class Solution {
    using ll=long long;
public:
    int maximumSum(vector<int>& nums) {
        ll n=nums.size();
        unordered_map<ll,ll>map;

        ll ans=-1;

        for(int i=0;i<n;i++){
            ll num=nums[i];
            ll sum=0;

            while(num>0){
                sum+=num%10;
                num/=10;
            }

            if(map.find(sum)!=map.end()){
                ll existing=map[sum];
                ans=max(ans,existing+nums[i]);
                map[sum]=max(existing,(ll)nums[i]);
            }
            else{
                map[sum]=nums[i];
            }
        }

        return ans;
    }
};