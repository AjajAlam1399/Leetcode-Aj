class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 1;

        // Prefix sums
        vector<vector<int>> row(n, vector<int>(m + 1, 0));
        vector<vector<int>> col(n + 1, vector<int>(m, 0));
        vector<vector<int>> diag1(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> diag2(n + 1, vector<int>(m + 1, 0));

        // Build prefix sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        // Try all top-left corners
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Try all square sizes >= 2
                for (int k = 2; i + k <= n && j + k <= m; k++) {

                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    // Check all rows
                    for (int r = i; r < i + k && ok; r++) {
                        if (row[r][j + k] - row[r][j] != target)
                            ok = false;
                    }

                    // Check all columns
                    for (int c = j; c < j + k && ok; c++) {
                        if (col[i + k][c] - col[i][c] != target)
                            ok = false;
                    }

                    // Check diagonals
                    int d1 = diag1[i + k][j + k] - diag1[i][j];
                    int d2 = diag2[i + k][j] - diag2[i][j + k];

                    if (ok && d1 == target && d2 == target) {
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
    }
};
