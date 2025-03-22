class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int>visted(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!visted[i]){
                vector<int>vec;
                dfs(i,graph,vec,visted);
                bool flag=true;
                for(int i=0;i<vec.size();i++){
                    if(graph[vec[i]].size()!=vec.size()-1){
                        flag=false;
                        break;
                    }
                }
                if(flag)ans++;
            }
        }
        return ans;

    }
    void dfs(int v,vector<vector<int>> &graph,vector<int>&ver,vector<int>&visted){
        ver.push_back(v);
        visted[v]=true;
        for(auto it : graph[v]){
            if(!visted[it]){
                dfs(it,graph,ver,visted);
            }
        }
    }
};