class Solution {
    using ll=long long ;
public:
    int minOperations(vector<int>& nums, int k) {
        ll n=nums.size();
        ll ans=0;
        priority_queue<ll,vector<ll>,greater<ll>>pq;

        for(ll i=0;i<n;i++){
            pq.push(nums[i]);
        }

        while(!pq.empty() && pq.top()<k){
            ll num1=pq.top();
            pq.pop();
            ll num2=pq.top();
            pq.pop();
            ll num=min(num1,num2)*2+max(num1,num2);
            pq.push(num);
            ans++;
        }
        return ans;
    }
};