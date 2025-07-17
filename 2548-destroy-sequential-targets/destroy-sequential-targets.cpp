class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int>map;
        int n=nums.size();
        int maxFcnt=0;
        for(int i=0;i<nums.size();i++){
            map[nums[i]%space]++;
            maxFcnt=max(maxFcnt,map[nums[i]%space]);
        }

        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            int mod=nums[i]%space;
            if(map[mod]==maxFcnt){
                ans=min(ans,nums[i]);
            }
        }

        return ans;
    }
};