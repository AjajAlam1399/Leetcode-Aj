class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)map[nums[i]]++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>0 && map.find(-nums[i])!=map.end()){
                ans=max(ans,nums[i]);
            }
        }

        return ans;
    }
};