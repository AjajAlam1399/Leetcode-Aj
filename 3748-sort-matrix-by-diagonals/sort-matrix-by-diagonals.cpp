class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int gap=0;gap<n;gap++){
            vector<int>vec;
            for(int i=gap,j=0;i<n;i++,j++){
                vec.push_back(grid[i][j]);
            }
            sort(vec.begin(),vec.end());
            for(int i=gap,j=0;i<n;i++,j++){
                grid[i][j]=vec.back();
                vec.pop_back();
            }
        }

        for(int gap=1;gap<n;gap++){
            vector<int>vec;
            for(int i=0,j=gap;i<n && j<n ; i++,j++){
                vec.push_back(grid[i][j]);
            }
            sort(vec.rbegin(),vec.rend());
            for(int i=0,j=gap;i<n && j<n ; i++,j++){
                grid[i][j]=vec.back();
                vec.pop_back();
            }
        }

        return grid;
    }
};