class Solution {
    int arr1[4]={-1,0,1,0};
    int arr2[4]={0,-1,0,1};
    int n,m;
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         n=grid1.size();
         m=grid1[0].size();
        vector<vector<bool>>visted(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visted[i][j] && grid2[i][j]){
                    bool ans=true;
                    if(!grid1[i][j])ans=false;
                    fun(i,j,grid1,grid2,visted,ans);
                    if(ans){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    void fun(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<bool>>&visted,
    bool &ans){
        visted[i][j]=true;

        for(int k=0;k<4;k++){
            int newi=i+arr1[k];
            int newj=j+arr2[k];
            if(newi>=0 && newj>=0 && newi<n && newj<m && 
            grid2[newi][newj] && !visted[newi][newj]){
                if(!grid1[newi][newj]){
                    ans=false;
                }
                fun(newi,newj,grid1,grid2,visted,ans);
            }
        }
    }
};