class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>vec;
        vec.push_back(0);
        int cnt=0;
        for(int i=1;i<n;i++){
            bool f1=false;
            bool f2=false;

            if(nums[i-1]%2==0)f1=true;
            if(nums[i]%2==0)f2=true;

            if(f1==f2)cnt++;
            vec.push_back(cnt);
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int s=queries[i][0];
            int e=queries[i][1];
            int diff=vec[e]-vec[s];
            if(diff)ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};