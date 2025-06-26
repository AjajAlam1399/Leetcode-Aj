class Solution {
    using ll =long long int;
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>>vec;
        for(auto int i=0;i<=n;i++){
            vec.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});
        }
        sort(vec.begin(),vec.end());
        priority_queue<int>avilable;
        priority_queue<int,vector<int>,greater<int>>pq;

        int j=0;
        int ans=0;

        for(int i=0;i<n;i++){

            while(!pq.empty() && i>=pq.top()){
                pq.pop();
            }
        
            while(j<=n && i>=vec[j][0]){
                avilable.push(vec[j][1]);
                j++;
            }
            
            if(pq.empty()){
                auto it=avilable.top();
                if(it>i){
                    // cout<<i<<endl;
                    ans++;
                    pq.push(it);
                    avilable.pop();
                }
                else{
                    return -1;
                }
            }
        }

        return ans;
    }
};