class Solution {
    int dp[20005];
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>map;
        vector<int>vec;

        memset(dp,-1,sizeof(dp));

        for(auto num:nums){
            if(!map.count(num)){
                vec.push_back(num);
            }
            map[num]++;
        }

        sort(vec.begin(),vec.end());

        return fun(0,vec,map);
    }

    int fun(int ind,vector<int>&nums,unordered_map<int,int>&map){

        if(ind==nums.size()){
            return 0;
        }

        if(dp[ind]!=-1)return dp[ind];

        int not_taken=fun(ind+1,nums,map);
        int nextInd=upper_bound(nums.begin(),nums.end(),nums[ind]+1)-nums.begin();
        int taken=nums[ind]*map[nums[ind]]+fun(nextInd,nums,map);

        return dp[ind]= max(taken,not_taken);
    }
};