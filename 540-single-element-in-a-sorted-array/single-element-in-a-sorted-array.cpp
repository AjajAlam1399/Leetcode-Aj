class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s=0,e=n-1;

        while(s<e){
            int mid = (s+e)/2;

            if(nums[mid]==nums[mid^1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }

        return nums[s];
    }
};