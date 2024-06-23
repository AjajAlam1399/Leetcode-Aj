class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int lt=0,lb=n-1,bt=0,bb=m-1;

        while(lt<n){
            bool flag=false;
            for(int i=0;i<m;i++){
                if(grid[lt][i]==1){
                    flag=true;
                    break;
                }
            }
            if(flag)break;
            lt++;
        }
        while(lb>=0){
            bool flag=false;
            for(int i=0;i<m;i++){
                if(grid[lb][i]==1){
                    flag=true;
                    break;
                }
            }
            if(flag)break;
            lb--;
        }

         while(bt<m){
            bool flag=false;
            for(int i=0;i<n;i++){
                if(grid[i][bt]==1){
                    flag=true;
                    break;
                }
            }
            if(flag)break;
            bt++;
        }
        while(bb>=0){
            bool flag=false;
            for(int i=0;i<n;i++){
                if(grid[i][bb]==1){
                    flag=true;
                    break;
                }
            }
            if(flag)break;
            bb--;
        }
        int len=lb-lt+1;
        int bred=bb-bt+1;
        return len*bred;
    }
};