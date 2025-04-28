class Solution {
    using ll=long long;
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        ll n=receiver.size();
        ll maxD=35;
        vector<vector<ll>>sumArr(n,vector<ll>(maxD,0));
        vector<vector<ll>>kthAnc(n,vector<ll>(maxD,0));
        for(int i=0;i<maxD;i++){
            for(int j=0;j<n;j++){
                if(!i){
                    kthAnc[j][i]=receiver[j];
                    sumArr[j][i]=receiver[j];
                }
                else{
                    kthAnc[j][i]=kthAnc[kthAnc[j][i-1]][i-1];
                    sumArr[j][i]=sumArr[j][i-1]+sumArr[kthAnc[j][i-1]][i-1];
                }
            }
        }

        ll ans=0;
        for(int i=0;i<n;i++){
            ll subans=i;
            ll node=i;
            for(ll j=0;j<maxD;j++){
                if(k&(1LL<<j)){
                    subans+=sumArr[node][j];
                    node=kthAnc[node][j];
                }
            }
            ans=max(ans,subans);
        }
        return ans;
    }
};