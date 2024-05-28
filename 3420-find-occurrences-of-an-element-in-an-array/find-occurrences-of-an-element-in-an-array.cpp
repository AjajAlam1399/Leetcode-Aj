class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,vector<int>>vec;
        int n=nums.size();

        for(int i=0;i<n;i++){
           if(nums[i]==x){
            vec[nums[i]].push_back(i);
           }
        }

        vector<int>ans;

            auto it=vec[x];

        for(int i=0;i<queries.size();i++){
            if(it.size()<queries[i]){
                ans.push_back(-1);
            }
            else{
                ans.push_back(it[queries[i]-1]);
            }
        }

        return ans;
    }
};