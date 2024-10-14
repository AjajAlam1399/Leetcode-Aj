class Solution {
    using ll=long long ;
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll n=nums.size();
        priority_queue<ll>pq;

        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        ll ans=0;
        while(!pq.empty() && k>0){
            if(pq.top()==0){
                break;
            }
            
            ans+=pq.top();
            ll val=pq.top();
            pq.pop();
            if(val%3==0){
                val=val/3;
            }
            else{
                val=val/3;
                val++;
            }
            pq.push(val);
            k--;
        }
        return ans;
    }
};