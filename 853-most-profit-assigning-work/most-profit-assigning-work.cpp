class Solution {
    using ll=long long;
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ll ans=0;
        int n=worker.size(),m=difficulty.size();

        for(int i=0;i<n;i++){
            ll work=worker[i];
            ll curr=0;
            for(int j=0;j<m;j++){
                if(difficulty[j]<=work){
                    curr=max(curr,(ll)profit[j]);
                }
            }
            ans+=curr;
        }
        return ans;
    }
};