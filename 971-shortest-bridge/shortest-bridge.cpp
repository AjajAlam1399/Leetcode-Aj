class Solution {
    vector<vector<int>> cost;
    deque<pair<int, int>> dq;

    int arr1[4]={-1,0,1,0};
    int arr2[4]={0,-1,0,1};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        cost.resize(n, vector<int>(m, INT_MAX));

        findStartPoint(grid);
        bool isfirstComplete=false;
        while(!dq.empty()){
            auto it=dq.front();
            int i=it.first;
            int j=it.second;
            dq.pop_front();

            if(grid[i][j]==0){
                isfirstComplete=true;
            }

            if(isfirstComplete && grid[i][j]){
                return cost[i][j];
            }

            for(int k=0;k<4;k++){
                int newi=i+arr1[k];
                int newj=j+arr2[k];

                if(newi>=0 && newj>=0 && newi<n && newj<m && cost[newi][newj]==INT_MAX){
                    cost[newi][newj]=min(cost[i][j],cost[newi][newj]);

                    if(grid[newi][newj]==1){
                        dq.push_front({newi,newj});
                    }
                    else{
                        cost[newi][newj]++;
                        dq.push_back({newi,newj});
                    }
                }
            }

        }

        return -1;
    }

    void findStartPoint(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dq.push_back({i, j});
                    cost[i][j] = 0;
                    return;
                }
            }
        }
    }
};