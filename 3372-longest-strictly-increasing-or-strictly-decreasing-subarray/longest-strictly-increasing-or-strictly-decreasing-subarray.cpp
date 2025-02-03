class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;

        for(int i=0;i<nums.size();i++){
            int cnt=1;
            int num=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(num<=nums[j]){
                    break;
                }
                else{
                    cnt++;
                    num=nums[j];
                }
                ans=max(ans,cnt);
            }
        }
        for(int i=0;i<nums.size();i++){
            int cnt=1;
            int num=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(num>=nums[j]){
                    break;
                }
                else{
                    cnt++;
                    num=nums[j];
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};