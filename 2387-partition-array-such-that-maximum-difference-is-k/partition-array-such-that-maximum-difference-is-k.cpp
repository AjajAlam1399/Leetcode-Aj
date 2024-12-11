class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();

        int i=0;
        int ans=0;
        sort(nums.begin(),nums.end());

        while(i<n){
            int sm=nums[i];
            while(i+1<n && nums[i+1]-sm<=k){
                i++;
            }
            ans++;
            i++;
        }
        return ans;
    }
};