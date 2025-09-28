class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());

        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];

            if(a==0 || b==0 || c==0)break;
            if(b+c>a){
                ans=max(ans,a+b+c);
            }
        }

        return ans;
    }
};