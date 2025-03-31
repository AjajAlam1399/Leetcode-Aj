class Solution {
    using ll=long long ;
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(n==k)return 0;
        priority_queue<ll>maxpq;
        priority_queue<ll,vector<ll>,greater<ll>>minpq;

        for(int i=1;i<n;i++){
            ll sum=weights[i]+weights[i-1];
            maxpq.push(sum);
            minpq.push(sum);
        }
        k--;
        ll ans=0;
        while(k>0){
            ans+=maxpq.top()-minpq.top();
            maxpq.pop();
            minpq.pop();
            k--;
        }
        return ans;

    }
};