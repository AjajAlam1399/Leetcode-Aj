class Solution {
    vector<vector<int>> adj;
    vector<int> freq;

    int dfsPath(int u, int target, int parent, vector<int>& path) {
        if (u == target) {
            path.push_back(u);
            return 1;
        }
        for (int v : adj[u]) {
            if (v != parent && dfsPath(v, target, u, path)) {
                path.push_back(u);
                return 1;
            }
        }
        return 0;
    }

    pair<long long, long long> dfsDP(int u, int parent, vector<int>& price) {
        long long notHalved = 1LL * price[u] * freq[u];
        long long halved = notHalved / 2;

        for (int v : adj[u]) {
            if (v == parent) continue;
            auto [childNotHalved, childHalved] = dfsDP(v, u, price);
            notHalved += min(childNotHalved, childHalved);
            halved += childNotHalved;  // Cannot halve child if u is halved
        }

        return {notHalved, halved};
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
                          vector<vector<int>>& trips) {
        adj.resize(n);
        freq.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 1: Count frequency of each node on all trips
        for (auto& trip : trips) {
            vector<int> path;
            dfsPath(trip[0], trip[1], -1, path);
            for (int node : path) {
                freq[node]++;
            }
        }

        // Step 2: Run tree DP
        auto [notHalved, halved] = dfsDP(0, -1, price);
        return min(notHalved, halved);
    }
};
