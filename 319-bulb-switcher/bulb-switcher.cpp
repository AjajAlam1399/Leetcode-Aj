class Solution {
    using ll=long long;
public:
    int bulbSwitch(int n) {

        if(n==0)return 0;
        
        int ans=1;

        ll curr=2;

        while(curr*curr<=n){
            ans++;
            curr++;
        }
        return ans;
    }
};