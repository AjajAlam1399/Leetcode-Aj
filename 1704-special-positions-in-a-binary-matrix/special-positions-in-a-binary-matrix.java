class Solution {
    public int numSpecial(int[][] mat) {
        int n=mat.length;
        int m=mat[0].length;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && check(mat,i,j)){
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
    boolean check(int [][]mat,int i,int j){
        int m=mat.length;
        int n=mat[0].length;

        for(int k=0;k<m;k++){
            if(k!=i){
                if(mat[k][j]==1){
                    return false;
                }
            }
        }
        for(int k=0;k<n;k++){
            if(k!=j){
                if(mat[i][k]==1){
                    return false;
                }
            }
        }

        return true;
    }
}