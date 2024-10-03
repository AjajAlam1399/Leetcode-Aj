class Solution {
    using ll=long long;
public:
    int minSubarray(vector<int>& nums, int p) {
        ll sum=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum<p) return -1;
        if(sum%p==0)return 0;

        unordered_map<int,int>map;
        map[0]=-1;
        int ans=INT_MAX;
        int l=sum%p;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int mod=sum%p;
            int targetMod=(mod-l+p)%p;
            if(map.find(targetMod)!=map.end()){
                ans=min(ans,i-map[targetMod]);
            }
            map[mod]=i;
        }
        return ans==INT_MAX || ans==n?-1:ans;
    }
};