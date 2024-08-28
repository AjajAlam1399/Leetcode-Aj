class Solution {
    int arr1[]={-1,0,1,0};
    int arr2[]={0,-1,0,1};
    int n,m;
    boolean ans;
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        n=grid1.length;
         m=grid1[0].length;
         
         int [][]visted=new int[n][m];
         for(int i=0;i<n;i++)Arrays.fill(visted[i],0);

         int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visted[i][j]==0 && grid2[i][j]==1){
                    ans=true;
                    if(grid1[i][j]==0){ans=false;}

                    fun(i,j,grid1,grid2,visted);

                    if(ans){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    void fun(int i,int j,int[][]grid1,int[][]grid2,int[][]visted){
        visted[i][j]=1;

        for(int k=0;k<4;k++){
            int newi=i+arr1[k];
            int newj=j+arr2[k];
            if(newi>=0 && newj>=0 && newi<n && newj<m && 
            grid2[newi][newj]==1 && visted[newi][newj]==0){
                if(grid1[newi][newj]==0){
                    ans=false;
                }
                fun(newi,newj,grid1,grid2,visted);
            }
        }
    }
}