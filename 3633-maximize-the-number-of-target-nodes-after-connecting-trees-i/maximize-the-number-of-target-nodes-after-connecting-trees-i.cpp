class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();

        vector<vector<int>> graph1(n+1), graph2(m+1);

        for (auto it : edges1) {
            graph1[it[0]].push_back(it[1]);
            graph1[it[1]].push_back(it[0]);
        }

        for (auto it : edges2) {
            graph2[it[0]].push_back(it[1]);
            graph2[it[1]].push_back(it[0]);
        }

        int maxcnt = 0;

        if (k > 0) {
            for (int i = 0; i < m+1; i++) {
                int curr = 1;
                fun(i, -1, 0, k - 1, curr, graph2);
                maxcnt=max(curr,maxcnt);
            }
        }

        vector<int>ans;

        for(int i=0;i<n+1;i++){
            int curr=1;
            fun(i,-1,0,k,curr,graph1);
            ans.push_back(curr+maxcnt);
        }

        return ans;
    }

    void fun(int node, int parent, int level, int k, int& cnt,
             vector<vector<int>>& graph) {
        if (level >= k)
            return;

        for (auto adjnode : graph[node]) {
            if (adjnode != parent) {
                cnt++;
                fun(adjnode, node, level + 1, k, cnt, graph);
            }
        }
    }
};