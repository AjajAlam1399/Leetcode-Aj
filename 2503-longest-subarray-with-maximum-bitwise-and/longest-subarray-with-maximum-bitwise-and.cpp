class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int maxVal=*max_element(nums.begin(),nums.end());

        int s=0,e=0;
        int ans=1;
        int curr=0;
        while(e<n){

            if(nums[e]==maxVal){
                ans=max(ans,e-s+1);
            }
            else{
                s=e+1;
            }
            e++;
        }

        return ans;
    }
};