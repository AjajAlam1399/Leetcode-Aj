class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>vec;
        fun(0,nums,ans,vec);

        return ans;
    }

    void fun(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&vec){


        if(ind==nums.size()){
            ans.push_back(vec);
            return;
        }

        vec.push_back(nums[ind]);
        fun(ind+1,nums,ans,vec);
        vec.pop_back();
        fun(ind+1,nums,ans,vec);
    }
};