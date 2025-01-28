class Solution {
    int arr1[4]={-1,0,1,0};
    int arr2[4]={0,-1,0,1};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();

        vector<vector<bool>>visted(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currans=0;
                if(grid[i][j]>0 && !visted[i][j]){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    currans+=grid[i][j];
                    visted[i][j]=true;

                    while(!q.empty()){
                        auto it =q.front();
                        q.pop();
                        int r=it.first;
                        int c=it.second;
                        for(int k=0;k<4;k++){
                            int newr=r+arr1[k];
                            int newc=c+arr2[k];
                            if(newr>=0 && newc>=0 && newr<n && newc<m &&
                            grid[newr][newc]>0 && !visted[newr][newc]
                            ){
                                visted[newr][newc]=true;
                                q.push({newr,newc});
                                currans+=grid[newr][newc];
                            }
                        }
                    }
                    ans=max(ans,currans);
                }
            }
        }

        return ans;
    }
};