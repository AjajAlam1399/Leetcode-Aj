class Solution {
    long long dp[1001][1001];
    int mod=1e9+7;
    using ll=long long;
public:
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int m=words[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<ll>>vec(m,vector<ll>(26,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vec[i][words[j][i]-'a']++;
            }
        }
        return fun(0,0,vec,target);
    }

    ll fun(int i,int j,vector<vector<ll>>&vec,string &target){

        if(j==target.size())return 1;
        if(i==vec.size())return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        ll not_taken=fun(i+1,j,vec,target)%mod;
        ll taken=0;
        if(vec[i][target[j]-'a']){
            taken=((vec[i][target[j]-'a']%mod)*(fun(i+1,j+1,vec,target)%mod))%mod;
        }
        return dp[i][j]=(taken+not_taken)%mod;
    }
};