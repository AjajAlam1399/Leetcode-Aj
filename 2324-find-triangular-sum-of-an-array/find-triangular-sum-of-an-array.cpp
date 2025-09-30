class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<int>vec;
            for(int j=0;j<nums.size()-1;j++){
                int sum=(nums[j]+nums[j+1])%10;
                vec.push_back(sum);
            }
            // for(auto e : vec)cout<<e<<" ";
            // cout<<endl;
            nums=vec;
        }
        return nums[0];
    }
};