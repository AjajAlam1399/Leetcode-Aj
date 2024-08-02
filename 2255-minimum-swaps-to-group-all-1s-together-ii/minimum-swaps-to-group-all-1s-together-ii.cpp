class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt=0,n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==1)cnt++;
        }
        if(cnt<=1)return 0;
        int ans=n;
        int s=0,e=0,currcnt=0;

        while(e<2*n){
            if(e-s+1<cnt){
                if(nums[e%n]==1)currcnt++;
                e++;
            }
            else if(e-s+1==cnt){
                if(nums[e%n]==1)currcnt++;
                int len=e-s+1-currcnt;
                ans=min(ans,len);
                if(nums[s%n]==1)currcnt--;
                s++;
                e++;
            }
        }
        return ans;
    }
};