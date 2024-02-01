class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int s=0;
        while(s<n){
             vector<int>subans;
            for(int i=s;i<s+3;i++){
                if(i==s)subans.push_back(nums[i]);
                else if(nums[i]-subans[0]>k)return {};
                else{
                    subans.push_back(nums[i]);
                }
            }
            s+=3;
            ans.push_back(subans);
        }
        return ans;
    }

};