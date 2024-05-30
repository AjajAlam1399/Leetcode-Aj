class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            bool f1=false,f2=false;
            if(nums[i]%2==0)f1=true;
            if(nums[i-1]%2==0)f2=true;

            if(f1==f2)return false;

        }
        return true;
    }
};