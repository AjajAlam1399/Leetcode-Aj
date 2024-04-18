class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>>visted(row,vector<bool>(col,false));
        queue<pair<int,int>>q;
        bool flag=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    flag=true;
                    break;

                }
            }
            if(flag)break;
        }
        int ans=0;

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int i=node.first;
            int j=node.second;
            if(visted[i][j]==true){
                continue;
            }
            visted[i][j]=true;
            int cnt=4;
            int arr1[]={-1,0,1,0};
            int arr2[]={0,-1,0,1};

            for(int dir=0;dir<4;dir++){
                int newi=i+arr1[dir];
                int newj=j+arr2[dir];

                if(newi>=0 && newj>=0 && newi<row && newj<col && grid[newi][newj]==1){
                    cnt-=1;
                    if(!visted[newi][newj]){
                        q.push({newi,newj});
                    }
                }
            }
            ans+=cnt;
        }
        return ans;
    }
};