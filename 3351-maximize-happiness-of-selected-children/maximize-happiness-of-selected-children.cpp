class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq;
        int n=happiness.size();

        for(int i=0;i<n;i++)pq.push(happiness[i]);

        long long ans=0;
        int taken=0;
        while(!pq.empty() && taken<k){
            auto top=pq.top();
            pq.pop();
            if(top-taken>0){
                ans+=top-taken;
            }
            else{
                break;
            }
            taken++;
        }
        return ans;
    }
};