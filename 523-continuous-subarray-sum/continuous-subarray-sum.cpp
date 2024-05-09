class Solution {
    using ll=long long;
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        map[0]=-1;

        ll sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int mod=sum%k;
            if(map.find(mod)!=map.end()){
                int len=i-map[mod];
                if(len>=2)return true;
            }
            else{
                map[mod]=i;
            }
        }
        return false;
    }
};