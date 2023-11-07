class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        priority_queue<double,vector<double>,greater<double>>pq;

        for(int i=0;i<n;i++){
            pq.push(((dist[i]*1.0)/(speed[i])));
        }
        double time=0;
        while(!pq.empty()){
            if(time>=pq.top()){
                break;
            }
            pq.pop();
            time+=1.0;
        }

        return time==0?1:time;
    }
};