class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,pair<int,int>>>>graph(n);

        for(auto it : edges){
            graph[it[0]].push_back({it[1],{it[2],it[3]}});
        }

        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();

            int node=it[1];
            int sec=it[0];

            for(auto [adjnode,range]:graph[node]){
                int s=range.first;
                int e=range.second;
                if(sec<=e){
                    int nextMove;

                    if(sec>=s){
                        nextMove=sec+1;
                    }
                    else{
                        nextMove=s+1;
                    }

                    if(dist[adjnode]>nextMove){
                        dist[adjnode]=nextMove;
                        pq.push({nextMove,adjnode});
                    }
                }
            }
        }

        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};