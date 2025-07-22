class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        int ans=0;
        unordered_map<int ,int >map;
        while(j<n){
            map[nums[j]]++;
            sum+=nums[j];
            while(i<j && map[nums[j]]>1){
                sum-=nums[i];
                map[nums[i]]--;
                i++;
            }
            j++;
            ans=max(ans,sum);
        }

        return ans;
    }
};