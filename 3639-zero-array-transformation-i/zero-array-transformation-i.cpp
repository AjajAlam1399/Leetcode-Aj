class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        vector<int>vec(n+1,0);

        for(int i=0;i<queries.size();i++){
            vec[queries[i][0]]++;
            vec[queries[i][1]+1]--;
        }
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=vec[i];
            if(nums[i]>sum)return false;
        }

        return true;
    }
};