class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int num=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt++;
                num=nums[i];
            }
            else if(nums[i]==num){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return num;
    }
};