class Solution {
    using pp=pair<int,int>;
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        priority_queue<pp,vector<pp>,greater<pp>>pq;

        int n=points.size(),i=0;
        int cnt=0;
        int start=INT_MIN;

        while(i<n || !pq.empty()){
            if(pq.empty()){
                pq.push({points[i][0],points[i][1]});
                start=max(start,pq.top().second);
                i++;
            }
            while(i<n && points[i][0]<=start){
                pq.push({points[i][0],points[i][1]});
                i++;
            }
            while(!pq.empty() && pq.top().first<=start){
                start=min(start,pq.top().second);
                pq.pop();
            }
            if(!pq.empty()){
                start=max(start,pq.top().second);
            }
            cnt++;
        }
        return cnt;
    }
};