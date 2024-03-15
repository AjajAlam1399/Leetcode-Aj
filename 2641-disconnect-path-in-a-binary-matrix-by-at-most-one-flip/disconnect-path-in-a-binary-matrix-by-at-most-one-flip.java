class Solution {
    public boolean isPossibleToCutPath(int[][] grid) {
        if(!dfs(0,0,grid)){
            return true;
        }
        
        if(!dfs(0,0,grid)){
            return true;
        }

        return false;
    }
    boolean dfs(int i,int j,int[][]grid){
        if(i>=grid.length || j>=grid[0].length){
            return false;
        }
        if(i==grid.length-1 && j==grid[0].length-1){
            return true;
        }
        if(grid[i][j]==1){
            if(i!=0 || j!=0){
                grid[i][j]=0;
            }
            if(dfs(i+1,j,grid) || dfs(i,j+1,grid)){
                return true;
            }
            
        }
        return false;
    }
}