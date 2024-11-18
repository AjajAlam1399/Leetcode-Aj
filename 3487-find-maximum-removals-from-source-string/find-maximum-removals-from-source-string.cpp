class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n=source.size();
        vector<int>vec(n);
        for(int i=0;i<targetIndices.size();i++){
            vec[targetIndices[i]]=1;
        }
        int n1=source.size(),n2=pattern.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return targetIndices.size()-fun(0,0,source,pattern,vec,dp);
    }
    int fun(int i,int j,string &source,string &pattern,vector<int>&vec,vector<vector<int>>&dp){

        if(j==pattern.size())return 0;
        if(i==source.size()) return 1e8;
        if(dp[i][j]!=-1)return dp[i][j];
        int not_taken=fun(i+1,j,source,pattern,vec,dp);
        int taken=1e9;
        if(source[i]==pattern[j]){
            taken=vec[i]+fun(i+1,j+1,source,pattern,vec,dp);
        }
        return dp[i][j]=min(taken,not_taken);
    }
};