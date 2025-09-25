class Solution {

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<int> curr(m + 1, 0);
        vector<int> prev(m + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                curr[j] = triangle[i][j] + min(prev[j], prev[j + 1]);
            }
            prev = curr;
        }
        return curr[0];
    }

    // int fun(int i,int j,vector<vector<int>>& triangle){

    //     if (i == triangle.size() - 1) {
    //         return triangle[i][j];
    //     }

    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     int next=triangle[i][j] + fun(i+1,j,triangle);
    //     int right=triangle[i][j]+fun(i+1,j+1,triangle);

    //     return dp[i][j]=min(next,right);
    // }
};