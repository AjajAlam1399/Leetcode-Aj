class Solution {
    using ll=long long ;
    ll mod=1e9+7;
public:
    int numOfSubarrays(vector<int>& arr){
        ll n=arr.size();
        ll o=0,e=1;
        ll sum=0,ans=0;
        for(ll i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                ans=(ans%mod+o%mod)%mod;
                e++;
            }
            else{
                ans=(ans%mod+e%mod)%mod;
                o++;
            }
        }
        return ans;
    }
};