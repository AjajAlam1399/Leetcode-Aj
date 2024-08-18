class Solution {
    using ll=long long;
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m=primes.size();

        vector<ll>ind(m);
        vector<ll>gen(m);
        vector<ll>dp(n+1);
        dp[0]=1;

        for(int i=1;i<=n;i++){
            ll minN=INT_MAX;
            for(int j=0;j<m;j++){
                gen[j]=dp[ind[j]]*primes[j];
                minN=min(gen[j],minN);
            }

            for(int j=0;j<m;j++){
                if(minN==gen[j]){
                    dp[i]=minN;
                    ind[j]++;
                }
            }
        }
        return dp[n-1];
    }
};