class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<=(n-k);i++){
            bool flag=true;
            int prev=nums[i];
            for(int j=i+1;j<i+k;j++){
                if(nums[j]-prev!=1){
                    flag=false;
                    break;
                }
                prev=nums[j];
            }
            if(flag)ans.push_back(prev);
            else ans.push_back(-1);
        }
        return ans;
    }
};