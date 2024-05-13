class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> vec;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (grid[i][0] !=1) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1)
                        grid[i][j] = 0;
                    else
                        grid[i][j] =1;
                }
            }
        }
        ans += ((n) * (1 << m - 1));
        // cout << ans << endl;

        for (int j = 1; j < m; j++) {
            int one = 0, zero = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] ==1)
                    one++;
                else
                    zero++;
            }
            ans += (max(one, zero) * (1 << m - 1 - j));
        }
        return ans;
    }
};