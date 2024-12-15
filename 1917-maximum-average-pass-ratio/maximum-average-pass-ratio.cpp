class Solution {
    using box=pair<double,pair<int,int>>;
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<box>pq;

        for(int i=0;i<classes.size();i++){
            double currRatio=(double)(classes[i][0])/(double)(classes[i][1]);
            double  increasedRatio=(double)(classes[i][0]+1)/(double)(classes[i][1]+1);
            double ratio=increasedRatio-currRatio;
            pq.push({ratio,{classes[i][0],classes[i][1]}});
        }

        while(extraStudents){
            auto it =pq.top();
            pq.pop();
            
            int p=it.second.first+1;
            int t=it.second.second+1;
            double currRatio=(double)(p)/(double)(t);
            double  increasedRatio=(double)(p+1)/(double)(t+1);
            double ratio=increasedRatio-currRatio;
            pq.push({ratio,{p,t}});
            extraStudents--;
        }
        double ans=0.0;

        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            
            int p=it.second.first;
            int t=it.second.second;
            ans+=(double)p/(double)t;
        }
        return ans/(double)classes.size();
    }
};