class Solution {
    using pp=pair<double,pair<int,int>>;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>ans;

        priority_queue<pp>pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double val=(double)arr[i]/(double)arr[j];
                if(pq.size()<k){
                    pq.push({val,{arr[i],arr[j]}});
                }
                else if(pq.size()==k && pq.top().first>val){
                    pq.pop();
                    pq.push({val,{arr[i],arr[j]}});
                }
            }
        }
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;

    }
};