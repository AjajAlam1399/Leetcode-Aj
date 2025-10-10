class Solution {
    using ll =long long;
    int mod=1e9+7;
public:
    int countOrders(int n) {
        ll prev=1;

        for(int i=2;i<=n;i++){
            ll space=(i-1)*2+1;
            ll totalC=(((space)%mod*(space+1)%mod)%mod)/2;
            prev=((prev%mod)*(totalC%mod))%mod;
        }
        return prev;
    }
};