class Solution {
    using ll=long long;
public:
    long long minimumSteps(string s) {
        ll ans1=0,ans2=0,n=s.size();
        ll index=n-1;
        for(ll i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ans1+=index-i;
                index--;
            }
        }
        index=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='0'){
                ans2+=i-index;
                index++;
            }
        }

        return min(ans1,ans2);

    }
};