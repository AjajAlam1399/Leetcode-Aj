class Solution {
    vector<vector<pair<int, int>>> adj;
    vector<int> depth;
    vector<vector<int>> kthParent;
    vector<unordered_map<int, int>> freq; // for each node, we will have frequency 
    vector<int> parent;
    int maxD = 0; 
    void dfs(int node, int p, int d){
        parent[node] = p;
        for(auto& [nei, val] : adj[node]){
            if(nei!= p){
                depth[nei] = d + 1;
                freq[nei] = freq[node];
                freq[nei][val]++;
                dfs(nei, node, d + 1);
            }
        }
    }
    int getKth(int u, int k){
        for(int i =0; i < maxD; ++i){
            if( (1<<i) & k)
                u = kthParent[u][i];
        }
        return u;
    }
    int getLCA(int u, int v){
        if(depth[u] > depth[v])
            swap(u, v);
        int diff = depth[v] - depth[u];
        v = getKth(v , diff) ; // v is on deeper ;evel, so we need to lift it up
        if(u==v) // case where both node are originally in same subtree
            return u;
        for(int i = maxD; i>=0 ; --i){
            int newU = kthParent[u][i];
            int newV = kthParent[v][i];
            if(newU==newV) // that means we are yet to find something not common, 
                continue;
            u = newU;
            v = newV;
        }
        // now here we have explored all the depth and now u and v parent is LCA
        return parent[u];
    }
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        adj.resize(n);
        depth.resize(n);
        freq.resize(n);
        parent.resize(n);
        while ( (1 << maxD) <=n ){
            ++maxD;
        }
        depth[0] = 0;
        kthParent.resize(n, vector<int>(maxD+1));
        
        for(auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
      
        dfs(0, -1, 0);
        for(int i =0 ; i < maxD; ++i){
            for(int j =0; j < n ; ++j){
                if(!i)
                    kthParent[j][i] = parent[j];
                else if(kthParent[j][i-1]!=-1)
                    kthParent[j][i] = kthParent[kthParent[j][i-1]][i-1];
            }
        }
  
        vector<int> ans;
        for(int i =0; i < queries.size(); ++i){
            int l = getLCA(queries[i][0], queries[i][1]);
            int length = depth[queries[i][0]] + depth[queries[i][1]] - (2 * depth[l]);
            int maxE = 0;
            for(int j =0; j < 27; ++j){
                int curr = freq[queries[i][0]][j] + freq[queries[i][1]][j] - (2 * freq[l][j]);
                maxE = max(maxE, curr);
            }
            ans.push_back(length - maxE);
        }

        return ans;
    }
};