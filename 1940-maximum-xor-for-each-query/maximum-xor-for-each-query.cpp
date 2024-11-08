class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int xorAll=0;
        for(int i=0;i<n;i++){
            xorAll^=nums[i];
        }
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            int k=0;
            for(int i=maximumBit-1;i>=0;i--){
                int bit=(xorAll&(1<<i));
                if(!bit){
                    k|=(1<<i);
                }
            }
            ans.push_back(k);
            xorAll^=nums[i];
        }
        return ans;
    }
};