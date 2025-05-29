class Solution {
public:
    void dfs(int node, int parent, int depth, vector<vector<int>>& tree, vector<int>& color, vector<int>& count) {
        color[node] = depth % 2;
        count[depth % 2]++;
        for (int child : tree[node]) {
            if (child != parent) {
                dfs(child, node, depth + 1, tree, color, count);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> tree1(n), tree2(m);
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        vector<int> color1(n), color2(m);
        vector<int> count1(2, 0), count2(2, 0);

        dfs(0, -1, 0, tree1, color1, count1);
        dfs(0, -1, 0, tree2, color2, count2);

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + max(count2[0], count2[1]);
        }
        return res;
    }
};
