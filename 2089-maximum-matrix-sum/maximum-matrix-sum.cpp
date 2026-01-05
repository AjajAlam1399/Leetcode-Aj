class Solution {
    using ll=long long;
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll ans=0;
        priority_queue<int>pq;

        int n=matrix.size(),m=matrix[0].size();
        int minVal=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<=0){
                    pq.push(matrix[i][j]);
                }
                else{
                    minVal=min(minVal,matrix[i][j]);
                    ans+=matrix[i][j];
                }
            }
        }

        if(pq.size() && pq.size()%2){
            int top = -1*pq.top();
            int minV=min(minVal,top);
            int maxV=max(minVal,top);

            ans-=minVal;
            ans+=maxV;
            ans-=minV;
            
            pq.pop();
        }

        while(pq.size()){
            ans-=pq.top();
            pq.pop();
        }

        return ans;
    }
};