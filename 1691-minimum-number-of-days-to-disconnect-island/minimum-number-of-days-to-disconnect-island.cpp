class disjointSet {
public:
    vector<int> parent;
    vector<int> size;

    disjointSet(int size) {
        parent.resize(size);
        this->size.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void groupBysize(int x, int y) {

        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return;
        if (size[rootx] > size[rooty]) {
            parent[rooty] = rootx;
        } else if (size[rootx] < size[rooty]) {
            parent[rootx] = rooty;
        } else {
            parent[rootx] = rooty;
            size[rooty]++;
        }
    }
};
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        disjointSet ds(n * m);
        int arr1[] = {-1, 0, 1, 0};
        int arr2[] = {0, -1, 0, 1};
        int cnt = 0;
        vector<int> present(n * m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int node1 = m * i + j;
                    present[node1] = 1;
                    cnt++;
                    for (int k = 0; k < 4; k++) {
                        int newi = i + arr1[k];
                        int newj = j + arr2[k];
                        if (newi >= 0 && newj >= 0 && newi < n && newj < m && grid[newi][newj]) {
                            int node2 = m * newi + newj;
                            ds.groupBysize(node1, node2);
                        }
                    }
                }
            }
        }
        if (cnt == 1)
            return 1;
        if (cnt == 0)
            return 0;
        unordered_set<int> set;
        for (int i = 0; i < n * m; i++) {
            if (present[i]) {
                // cout<<i<<" ";
                int parent = ds.find(i);
                if (set.find(parent) == set.end()) {
                    set.insert(parent);
                }
            }
        }
        if (set.size() > 1)
            return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    bool flag = false;
                    for (int k = 0; k < 4; k++) {
                        int newi = i + arr1[k];
                        int newj = j + arr2[k];
                        if (newi >= 0 && newj >= 0 && newi < n && newj < m &&
                            grid[newi][newj]) {
                            flag = true;
                            if (check(newi, newj, grid, cnt - 1))
                                return 1;
                            if (flag)
                                break;
                        }
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    bool check(int i, int j, vector<vector<int>>& grid, int res) {
        int n = grid.size(), m = grid[0].size();

        int arr1[] = {-1, 0, 1, 0};
        int arr2[] = {0, -1, 0, 1};

        vector<vector<int>> visted(n, vector<int>(m, 0));
        visted[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        int cnt = 1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int ci = it.first;
            int cj = it.second;

            for (int k = 0; k < 4; k++) {
                int newi = ci + arr1[k];
                int newj = cj + arr2[k];

                if (newi >= 0 && newj >= 0 && newi < n && newj < m &&
                    grid[newi][newj] && !visted[newi][newj]) {
                    cnt++;
                    visted[newi][newj] = 1;
                    q.push({newi, newj});
                }
            }
        }

        return cnt != res;
    }
};