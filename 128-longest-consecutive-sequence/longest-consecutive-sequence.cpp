class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>map;

        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(map.count(nums[i]-1))continue;
            int cnt=0;
            int val=nums[i];
            while(map.count(val)){
                cnt++;
                val++;
            }
            ans=max(ans,cnt);
            if(cnt>nums.size()/2)break;
        }

        return ans;
    }
};