class Solution {
public:
    int countPrimes(int n) {
        vector<int>isprime(n+1,1);

        for(int i=2;i<=n;i++){
            if(isprime[i]){
                for(long long j=(long long)i*i;j<=n;j+=i){
                    isprime[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isprime[i])cnt++;
        }
        return cnt;
    }

};