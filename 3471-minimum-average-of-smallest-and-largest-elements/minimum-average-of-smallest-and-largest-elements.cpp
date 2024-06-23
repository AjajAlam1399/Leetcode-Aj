class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),s=0;
        int e=n-1;
        double ans=51;
        while(s<e){
            double curr=(nums[s]+nums[e])/2.0;
            ans=min(ans,curr);
            s++;
            e--;
        }
        return ans;
    }
};