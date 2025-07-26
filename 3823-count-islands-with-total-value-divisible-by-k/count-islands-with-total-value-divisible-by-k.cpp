#define ll long long
class dsu {
public:
    vector<int> size;
    vector<int> parent;
    vector<ll> sum;

    int n;

    dsu(int n, vector<ll>& nums) {
        this->n = n;
        size.resize(n, 1);
        parent.resize(n, 0);
        sum.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sum[i] = nums[i];
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void groupBySize(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);

        if (rootx == rooty) {
            return;
        }
        if (size[rootx] < size[rooty]) {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
            sum[rooty] += sum[rootx];
        } else {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
            sum[rootx] += sum[rooty];
        }
    }
    int count(int k) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                if (sum[i]>0 && sum[i] % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
class Solution {
    int arr1[4] = {-1, 0, 1, 0};
    int arr2[4] = {0, -1, 0, 1};

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<ll> vec(n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int ind = i * m + j;
                    vec[ind] = grid[i][j];
                }
            }
        }


        dsu ds(n * m, vec);

        vector<vector<int>> visted(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !visted[i][j]) {
                    queue<vector<int>> q;
                    q.push({i, j});
                    visted[i][j] = true;

                    while (!q.empty()) {
                        auto it = q.front();
                        q.pop();
                        int x = it[0];
                        int y = it[1];
                        int ind1 = x * m + y;

                        for (int k = 0; k < 4; k++) {
                            int newx = x + arr1[k];
                            int newy = y + arr2[k];

                            if (newx >= 0 && newy >= 0 && newx < n &&
                                newy < m && !visted[newx][newy] && grid[newx][newy]) {
                                visted[newx][newy] = true;
                                int ind2 = newx * m + newy;
                                ds.groupBySize(ind1, ind2);
                                q.push({newx, newy});
                            }
                        }
                    }
                }
            }
        }

        return ds.count(k);
    }
};