class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>map;
        int ele=0;
        for(auto num:nums){
            map[num]++;
            if(map[num]>nums.size()/2){
                ele=num;
            }
        }
        int totalcnt=map[ele],cnt=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                cnt++;
            }
            int leftRem=i+1-cnt;
            int rightEle=totalcnt-cnt;

            if(cnt>leftRem && rightEle>nums.size()-i-1-rightEle){
                ans=i;
                break;
            }
        }
        return ans;

    }
};