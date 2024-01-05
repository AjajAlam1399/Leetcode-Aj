class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
         vector<int>v;
    v.push_back(nums[0]);
    
    for(int i=1;i<n;i++){
        if(nums[i]>v.back()){
            v.push_back(nums[i]);
        }
        else if(nums[i]==v.back()){
            continue;
        }
        else{
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            v[it-v.begin()]=nums[i];
        }
    }
    return v.size();
}
    
};