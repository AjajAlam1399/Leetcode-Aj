class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);

        for(int i=0;i<n;i++){
            int orel=nums[i];
            for(int j=31;j>=0;j--){
                int bit=((orel)&(1<<j));
                if(bit){
                    int posAns=(orel&(~(1<<j)));
                    if((posAns|(posAns+1))==orel){
                        ans[i]=posAns;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};