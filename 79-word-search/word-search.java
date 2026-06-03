class Solution {
    int[] arr1 = {0,1,-1,0};
    int arr2[] = {1,0,0,-1};
    public boolean exist(char[][] board, String word) {
        
        int n=board.length;
        int m = board[0].length;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word.charAt(0)){
                    board[i][j] ='.';
                    if(fun(i,j,1,board,word))return true;
                    board[i][j]=word.charAt(0);
                }
            }
        }

        return false;
    }

    boolean fun(int i,int j,int ind ,char[][] board, String word ){
        if(ind==word.length())return true;


        for(int dir =0;dir<4;dir++){
            int newi = i+arr1[dir];
            int newj = j + arr2[dir];

            if(newi>=0  && newj>=0 && newi<board.length && newj<board[0].length && board[newi][newj]==word.charAt(ind)){
                char ch = board[newi][newj];
                board[newi][newj]='.';
                if(fun(newi,newj,ind+1,board,word))return true;
                board[newi][newj] = ch;
            }
        }

        return false;
    }
}