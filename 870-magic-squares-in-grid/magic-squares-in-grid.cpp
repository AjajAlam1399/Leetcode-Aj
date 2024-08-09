class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt=0,n=grid.size(),m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+2<n && j+2<m){
                    if(check(i,j,grid)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    bool check(int r,int c,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        unordered_set<int>set;
        unordered_set<int>set2;
        for(int i=r;i<=r+2;i++){
            int sum1=0;
            for(int j=c;j<=c+2;j++){
                if(grid[i][j]>9 || grid[i][j]==0)return false;
                sum1+=grid[i][j];
                set2.insert(grid[i][j]);
            }
            set.insert(sum1);
            if(set.size()>1)return false;
        }
        if(set2.size()!=9)return false;
        for(int j=c;j<=c+2;j++){
            int sum1=0;
            for(int i=r;i<=r+2;i++){
                if(grid[i][j]>9 || grid[i][j]==0)return false;
                sum1+=grid[i][j];
            }
            set.insert(sum1);
            if(set.size()>1)return false;
        }
        int i=r,j=c,sum1=0,sum2=0;
        while(i<r+3 && j<c+3){
            if(grid[i][j]>9 || grid[i][j]==0)return false;
            sum1+=grid[i][j];
            i++;
            j++;
        }
        set.insert(sum1);
        if(set.size()>1)return false;
        i=r+2;
        j=c+2;
        sum1=0;

        while(i>=r && j>=c){
            if(grid[i][j]>9 || grid[i][j]==0)return false;
            sum1+=grid[i][j];
            i--;
            j--;
        }
        set.insert(sum1);
        if(set.size()>1)return false;
        return true;
    }
};