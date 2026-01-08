class Solution {
    using ll = long long;
    // ll dp[505][505][2];
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        // memset(dp,-1e9,sizeof(dp));/

        vector<vector<vector<ll>>>dp(n1+1,vector<vector<ll>>(n2+1, vector<ll>(2, -1e9)));

        return fun(n1-1,n2-1,false,nums1,nums2,dp);
    }

    ll fun(int ind1 , int ind2 , bool flag,vector<int>& nums1, vector<int>& nums2 , vector<vector<vector<ll>>>&dp ){

        if(ind1<0 || ind2<0) {
            if(!flag)return -1e9;
            return 0;
        }

        if(dp[ind1][ind2][flag]!=-1e9) return dp[ind1][ind2][flag];

        ll not_taken1 = fun(ind1-1,ind2,flag,nums1,nums2,dp);
        ll not_taken2= fun(ind1,ind2-1,flag,nums1,nums2,dp);

        ll taken = (ll)nums1[ind1]*(ll)nums2[ind2] + fun(ind1-1,ind2-1,true,nums1,nums2,dp);

        return dp[ind1][ind2][flag] = max(not_taken1, max(not_taken2, taken));

    }
};