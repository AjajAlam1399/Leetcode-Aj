class Solution {
    using ll=long long;
public:
    long long countBadPairs(vector<int>& nums) {
        ll n=nums.size(),cnt=0;
        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            if(map.find(nums[i]-i)!=map.end()){
                cnt+=map[nums[i]-i];
            }
            map[nums[i]-i]++;
        }
        ll total=((n)*(n-1))/2;
        return total-cnt;
    }
};