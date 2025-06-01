class Solution {
    using ll=long long;
public:
    long long distributeCandies(int n, int limit) {
        
        if(n>3*limit)return 0;

        ll it=min(n,limit);
        ll ans=0;
        

        for(ll i=0;i<=it;i++){
            ll rem=n-i;

            if(rem>limit){
                ll a=limit;
                ll b=rem-a;

                if(b>limit)continue;
                if(a==b)ans++;
                else {
                    ll diff=max(a,b)-min(a,b);
                    ans+=diff+1;
                }
            }
            else{
                ans+=rem+1;
            }
        }

        return ans;
    }
};