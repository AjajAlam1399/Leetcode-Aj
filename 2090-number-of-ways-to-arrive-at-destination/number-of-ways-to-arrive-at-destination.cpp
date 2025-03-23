class Solution {
    int mod=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>>vec[n];

        for(auto it : roads){
            vec[it[0]].push_back({it[1],it[2]});
            vec[it[1]].push_back({it[0],it[2]});
        }

        vector<long long>dist(n,1e15);
        vector<long long>count(n,0);
        count[0]=1;
        dist[0]=0;

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,
        greater<pair<long long,long long>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            long long  we=it.first;
            int node=it.second;

            for(auto u : vec[node]){
                long long currwe=u.second;
                int adjnode=u.first;
                if((long long)dist[adjnode]>(long long)currwe+we){
                    dist[adjnode]=currwe+we;
                    pq.push({currwe+we,adjnode});
                    count[adjnode]=count[node];
                }
                else if((long long)dist[adjnode]==(long long)currwe+we){
                    count[adjnode]+=count[node];
                    count[adjnode]%=mod;
                }
            }
        }

        return count[n-1];
    }
};