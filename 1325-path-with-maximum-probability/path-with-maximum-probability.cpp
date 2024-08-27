class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, 
    vector<double>& succProb, int start_node, int end_node) {
        double maxq=(((-1e7)*(1.0))/1.0);
        vector<double>dist(n,maxq);

        vector<pair<int,double>>graph[n];

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        dist[start_node]=0;
        priority_queue<pair<int,double>>pq;
        pq.push({start_node,1});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.first;
            double currdist=it.second;

            for(auto adjnode:graph[node]){
                double addist=currdist*adjnode.second;
                if(addist>dist[adjnode.first]){
                    pq.push({adjnode.first,addist});
                    dist[adjnode.first]=addist;
                }
            }

            
        }
        return dist[end_node]==maxq?0:dist[end_node];


        return 0;
    }
};