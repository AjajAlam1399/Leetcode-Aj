class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>>rowm;
        vector<pair<int,int>>colm;

        for(int i=0;i<n;i++){
            int zero=0,one=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    zero++;
                }
                else{
                    one++;
                }
            }
            rowm.push_back({one,zero});
        }

        for(int i=0;i<m;i++){
            int zero=0,one=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==0){
                    zero++;
                }
                else{
                    one++;
                }
            }
            colm.push_back({one,zero});
        }
        for(int i=0;i<n;i++){
                auto it1=rowm[i];
            for(int j=0;j<m;j++){
                auto it2=colm[j];
                grid[i][j]=it1.first+it2.first-it1.second-it2.second;
            }
        }
        return grid;
    }
};