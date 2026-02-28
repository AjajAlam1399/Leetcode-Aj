class Solution {
    int mod = 1000000000+7;
    public int concatenatedBinary(int n) {
        int pow2=1;

        int ans = 0;

        for(int i=n;i>0;i--){
            int curr = i;

            while(curr>0){
                int bit = ((curr)&(1));
                if(bit==1){
                    ans = (ans + pow2)%mod;
                }
                pow2 = (pow2%mod*2%mod)%mod;
                curr=curr>>1;
            }
        }

        return ans;
    }
}