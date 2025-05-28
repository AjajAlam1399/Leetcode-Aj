class Solution {
    class BL {
        int n, maxd;
        vector<vector<int>> bl;
        vector<vector<int>> graph;
        vector<int> parent;
        vector<int> depth;

    public:
        BL(int n, vector<vector<int>>& graph) {
            this->n = n;
            this->graph = graph;
            maxd = log2(n) + 2;
            bl.resize(n, vector<int>(maxd, -1));
            parent.resize(n, -1);
            depth.resize(n, 0);
            dfs(0, -1, 0);
            build();
        }

        void dfs(int node, int p, int d) {
            parent[node] = p;
            depth[node] = d;
            for (auto adjnode : graph[node]) {
                if (adjnode != p) {
                    dfs(adjnode, node, d + 1);
                }
            }
        }

        void build() {
            for (int i = 0; i < n; i++) {
                bl[i][0] = parent[i];
            }
            for (int j = 1; j < maxd; j++) {
                for (int i = 0; i < n; i++) {
                    int mid = bl[i][j - 1];
                    if (mid != -1)
                        bl[i][j] = bl[mid][j - 1];
                }
            }
        }

        int findkth(int node, int k) {
            for (int i = 0; i < maxd && node != -1; i++) {
                if ((k >> i) & 1) {
                    node = bl[node][i];
                }
            }
            return node;
        }

        int lca(int u, int v) {
            if (depth[u] > depth[v]) swap(u, v);
            int diff = depth[v] - depth[u];
            v = findkth(v, diff);
            if (u == v) return u;

            for (int i = maxd - 1; i >= 0; i--) {
                if (bl[u][i] != -1 && bl[v][i] != -1 && bl[u][i] != bl[v][i]) {
                    u = bl[u][i];
                    v = bl[v][i];
                }
            }
            return parent[u];
        }

        int findDist(int x, int y) {
            return depth[x] + depth[y] - 2 * depth[lca(x, y)];
        }

        void findmaxDepth(int node, int parent, int level, int& nod, int& currdepth) {
            if (level > currdepth) {
                currdepth = level;
                nod = node;
            }
            for (auto adjnode : graph[node]) {
                if (adjnode != parent) {
                    findmaxDepth(adjnode, node, level + 1, nod, currdepth);
                }
            }
        }
    };

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        if (n == 1 && m == 1) return 1;

        vector<vector<int>> graph1(n), graph2(m);

        for (auto& it : edges1) {
            graph1[it[0]].push_back(it[1]);
            graph1[it[1]].push_back(it[0]);
        }

        for (auto& it : edges2) {
            graph2[it[0]].push_back(it[1]);
            graph2[it[1]].push_back(it[0]);
        }

        BL bl1(n, graph1);
        BL bl2(m, graph2);

        int ax = 0, ay = 0, bx = 0, by = 0;
        int currdist1 = 0, currdist2 = 0;

        bl1.findmaxDepth(0, -1, 0, ax, currdist1);
        currdist1 = 0;
        bl1.findmaxDepth(ax, -1, 0, ay, currdist1);

        bl2.findmaxDepth(0, -1, 0, bx, currdist2);
        currdist2 = 0;
        bl2.findmaxDepth(bx, -1, 0, by, currdist2);

        int dist1 = bl1.findDist(ax, ay);
        int dist2 = bl2.findDist(bx, by);
        int adddist=(dist1 + 1) / 2 + (dist2 + 1) / 2 + 1;

        return max({dist1,dist2,adddist});
    }
};
