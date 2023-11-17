class Solution {
public:
    int minPairSum(vector<int>& nums) {
        if(nums.size()==2){
            return nums[0]+nums[1];
        }

        int n=nums.size();

        sort(nums.begin(),nums.end());
        int l=nums[0]+nums[1];
        int h=nums[n-1]+nums[n-2];

        int ans=h;

        while(l<h){
            int mid=(l+h)/2;
            if(fun(nums,mid)){
                ans=min(ans,mid);
                h=mid;
            }
            else{
                l=mid+1;
            }

        }

        return ans;
    }
    bool fun(vector<int>&nums,int mid){
        int s=0;
        int e=nums.size()-1;

        while(s<=e){
            if(nums[s]+nums[e]<=mid){
                s++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};