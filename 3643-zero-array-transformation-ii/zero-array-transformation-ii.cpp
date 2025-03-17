class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        if(!check(n-1,queries,nums))return -1;
        long long sum=0;
        for(auto it : nums){
            sum+=it;
        }
        if(sum==0)return 0;
        int s=0,e=n-1;
        int ans=s;

        while(s<=e){
            int mid=(s+e)/2;
            if(check(mid,queries,nums)){
                ans=mid+1;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    bool check(int e,vector<vector<int>>& queries,vector<int>& nums){
        int n=nums.size();
        vector<int>sumArr(n+1,0);

        for(int i=0;i<=e;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            sumArr[l]+=val;
            sumArr[r+1]-=val;
        }
        for(int i=1;i<n;i++){
            sumArr[i]+=sumArr[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>sumArr[i])return false;
        }
        return true;

    }
};