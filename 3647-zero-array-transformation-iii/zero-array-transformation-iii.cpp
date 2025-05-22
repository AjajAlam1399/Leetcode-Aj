class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size();

        sort(queries.begin(),queries.end());

        priority_queue<int,vector<int>,greater<int>>pq;
        priority_queue<int>avilable;

        int ans=0;
        int i=0,j=0;

        while(i<n){
            while(!pq.empty() && i>pq.top()){
                pq.pop();
            }
            while(j<m && i>=queries[j][0]){
                avilable.push(queries[j][1]);
                j++;
            }
            while(pq.size()<nums[i] && !avilable.empty() && avilable.top()>=i){
                ans++;
                pq.push(avilable.top());
                avilable.pop();
            }
            if(pq.size()<nums[i])return -1;
            i++;
        }
        return m-ans;
    }
};