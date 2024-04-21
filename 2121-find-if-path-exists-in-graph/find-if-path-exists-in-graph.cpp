class Solution {
public:
    bool dfs(int src,vector<int>graph[],vector<bool>&visted,int dest){
            visted[src]=true;
            if(src==dest){
                return true;
            }
            for(auto it : graph[src]){
                if(!visted[it]){
                    if(dfs(it,graph,visted,dest)){
                        return true;
                    }
                }
            }

            return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>graph[n];

        for(auto it :edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool>visted(n);
        return dfs(source,graph,visted,destination);
    }
};