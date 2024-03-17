class Solution {
    int mod = 1000000000+7;
    long ans=-1;
    public int maxProductPath(int[][] grid) {
        fun(0,0,grid[0][0],grid);
        return ans<0?-1:(int)(ans%mod);
    }

    void fun(int i,int j,long currans,int [][] grid){
        if(i==grid.length-1 && j==grid[0].length-1){
            ans=Math.max(ans,currans);
            return;
        }
        if(grid[i][j]==0){
            ans=Math.max(ans,0);
            return;
        }
        if(i+1<grid.length){
            fun(i+1,j,currans*grid[i+1][j],grid);
        }
        if(j+1<grid[0].length){
        fun(i,j+1,currans*grid[i][j+1],grid);
        }
        return;
    }
}