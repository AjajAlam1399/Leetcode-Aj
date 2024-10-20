class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int val=nums[n-1];
        int cnt=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=val){
                val=nums[i];
                continue;
            }
            int div=val;
            bool flag=false;
            while(div>1){
                if(nums[i]%div==0){
                    flag=true;
                    break;
                }
                div--;
            }
            if(!flag){
                return -1;
            }
            cnt++;
            val=div;

        }
        return cnt;
    }
};