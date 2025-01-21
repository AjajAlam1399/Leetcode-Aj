class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        if(derived.size()==1){
            return derived[0]==0;
        }
        vector<vector<vector<int>>>dp(2,
        vector<vector<int>>(2,vector<int>(n,-1)));
        bool ans=false;
        if(derived[0]){
            ans=fun(0,1,1,derived,dp)|fun(1,0,1,derived,dp);
        }
        else{
            ans=fun(1,1,1,derived,dp)|fun(0,0,1,derived,dp);
        }
        return ans;
    }

    bool fun(int start,int last,int ind,vector<int>&derived,
    vector<vector<vector<int>>>&dp){
        if(ind==derived.size()-1){
            return (last^start)==derived[ind];
        }
        if(dp[start][last][ind]!=-1)return dp[start][last][ind];
        if(derived[ind]){
            if(last){
                return dp[start][last][ind] = fun(start,0,ind+1,derived,dp);
            }
            else return dp[start][last][ind]= fun(start,1,ind+1,derived,dp);
        }
        else {
            if(last){
                return dp[start][last][ind] = fun(start,1,ind+1,derived,dp);
            }
            else return dp[start][last][ind] = fun(start,0,ind+1,derived,dp);
        }
        return dp[start][last][ind] = false;
    }
};