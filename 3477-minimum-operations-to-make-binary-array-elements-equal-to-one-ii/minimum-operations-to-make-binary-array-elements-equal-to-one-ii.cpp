class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i]==0){
                if(ans%2==0)ans++;
            }
            else{
                if(ans%2!=0)ans++;
            }
        }
        return ans;
        
    }
};