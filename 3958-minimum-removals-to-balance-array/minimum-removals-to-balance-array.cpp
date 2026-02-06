class Solution {
    using ll=long long;
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int ind = fun(nums[i],i,k,nums);
            ans=min(ans,i+n-1-ind);
        }
        return ans;

    }

    int fun(int val,int ind,int k,vector<int>&arr){
        int n=arr.size();
        int s=ind,e=n-1;

        int ans=s;

        while(s<=e){
            int mid=(s+e)/2;

            ll currVal = (ll)val*(ll)k;

            if(currVal>=arr[mid]){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return ans;
    }
};