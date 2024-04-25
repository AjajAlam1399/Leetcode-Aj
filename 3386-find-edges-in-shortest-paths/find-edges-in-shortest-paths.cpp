class Solution {
    using ll=long long;
    using pp=pair<ll,ll>;
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pp>>graph(n);
        for(auto it:edges){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        auto dis1=fun(graph,0);
        auto dis2=fun(graph,n-1);

        vector<bool>ans;
        for(auto it:edges){
            if((dis1[it[0]]+dis2[it[1]]+it[2]==dis1[n-1]) || 
            (dis1[it[1]]+dis2[it[0]]+it[2]==dis1[n-1]) ){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }

    vector<ll>fun(vector<vector<pp>>&graph,int node){
        int n=graph.size();
        vector<ll>dis(n,INT_MAX);
        dis[node]=0;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,node});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int currdis=top.first;
            int node=top.second;

            for(auto adjnode:graph[node]){
                ll wt=adjnode.second;
                int adjn=adjnode.first;
                if(dis[adjn]>currdis+wt){
                    dis[adjn]=currdis+wt;
                    pq.push({currdis+wt,adjn});
                }
            }
        }
        return dis;
    }
};