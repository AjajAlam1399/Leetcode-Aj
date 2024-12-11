class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int mi=1,mo=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                mo=mi+1;
            }
            else if(nums[i]<nums[i-1]){
                mi=mo+1;
            }
        }

        return max(mi,mo);
    }
};