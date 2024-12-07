class Solution {
public:
    int minimumSize(vector<int>& nums, int maxO) {
        int n=nums.size();
        int s=1,e=*max_element(nums.begin(),nums.end());
        int ans=e;
        while(s<=e){
            int mid=(e+s)/2;
            if(check(nums,maxO,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    bool check(vector<int>&nums,int maxO,int currans){

        int currcnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>currans){
                currcnt+=nums[i]/currans;
                if(nums[i]%currans==0)currcnt--;
                if(currcnt>maxO)return false;
            }
        }
        return true;
    }
};