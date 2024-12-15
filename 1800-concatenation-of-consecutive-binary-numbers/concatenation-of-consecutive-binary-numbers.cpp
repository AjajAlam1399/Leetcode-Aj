class Solution {
    int mod=1e9+7;
public:
    int concatenatedBinary(int n) {
        
        int powlen=0;
        long long ans=0;

        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                powlen++;
            }
            ans=((ans<<powlen)%mod+i)%mod;
        }
        return ans;
    }
};