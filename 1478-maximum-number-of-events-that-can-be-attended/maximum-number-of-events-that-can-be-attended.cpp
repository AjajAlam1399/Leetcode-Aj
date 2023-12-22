class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int res=0, ind=0;
        for(int i=1;i<=1e5;i++){
            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }
            while(ind<events.size() && events[ind][0]==i){
                pq.push({events[ind++][1]});
            }
            if(!pq.empty()){
                res++;
                pq.pop();
            }
        }
        return res;
    }
};