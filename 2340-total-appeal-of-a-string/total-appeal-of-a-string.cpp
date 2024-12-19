class Solution {
    using ll=long long ;
public:
    long long appealSum(string s) {
        
        ll ans=0;
        for(int i=0;i<=25;i++){
            ans+=fun(i,s);
        }
        return ans;
    }

    ll fun(int ind,string &s){
        ll ans=0;
        ll i=0,n=s.size();

        while(i<n){
            ll cnt=0;
            while(i<n && (s[i]-'a')!=ind){
                i++;
                cnt++;
            }
            ans+=((cnt)*(cnt+1))/2;
            i++;
        }

        return (((n)*(n+1))/2)-ans;
    }
};