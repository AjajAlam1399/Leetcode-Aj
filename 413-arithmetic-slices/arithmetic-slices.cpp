class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        for(int i=1;i<n-1;i++){
            int diff=nums[i]-nums[i-1];
            int cnt=2;
            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[j-1]==diff){
                    cnt++;
                    if(cnt>=3){
                        ans++;
                    }
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};