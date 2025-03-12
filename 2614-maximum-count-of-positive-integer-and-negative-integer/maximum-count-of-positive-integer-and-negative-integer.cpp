class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int negCnt=lastNegativeInd(nums)+1;
        int posCnt=n-firstPositiveInd(nums);
        return max(negCnt,posCnt);
    }
    int lastNegativeInd(vector<int>&nums){
        int n=nums.size();
        int ans=-1;
        int s=0,e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]<0){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    int firstPositiveInd(vector<int>&nums){
        int n=nums.size();
        int ans=n;
        int s=0,e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]>0){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};