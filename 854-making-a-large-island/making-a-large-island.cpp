class disjointSet {

public:
    vector<int> parent;
    vector<int> size;
    disjointSet(int n) {
        parent.resize(n);
        size.resize(n,1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
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

        if (rootx == rooty)
            return;
        if (size[rootx] >= size[rooty]) {
            parent[rooty] = rootx;
            size[rootx] += size[rooty];
        } else {
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet ds(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int arr1[] = {-1, 0, 1, 0};
                    int arr2[] = {0, -1, 0, 1};
                    for (int k = 0; k < 4; k++) {
                        int newi = i + arr1[k];
                        int newj = j + arr2[k];
                        if (newi >= 0 && newj >= 0 && newi < n && newj < n &&
                            grid[newi][newj]) {
                            int x = i * n + j;
                            int y = newi * n + newj;
                            ds.groupBySize(x, y);
                        }
                    }
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    int arr1[] = {-1, 0, 1, 0};
                    int arr2[] = {0, -1, 0, 1};
                    set<int> set;
                    for (int k = 0; k < 4; k++) {
                        int newi = i + arr1[k];
                        int newj = j + arr2[k];
                        if (newi >= 0 && newj >= 0 && newi < n && newj < n &&
                            grid[newi][newj]) {
                            int y = newi * n + newj;
                            int rooty = ds.find(y);
                            set.insert(rooty);
                        }
                    }
                    int cnt = 1;
                    for (auto it = set.begin(); it != set.end(); it++) {
                        cnt += ds.size[*it];
                    }
                    ans = max(ans, cnt);
                }else{
                    int x=i*n+j;
                    int rootx=ds.find(x);
                    int size=ds.size[rootx];
                    ans=max(ans,size);
                }
            }
        }
        return ans;
    }
};