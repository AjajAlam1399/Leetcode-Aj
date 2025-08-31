class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fun(board);
    }

    bool fun(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(check(i,j,board,ch)){
                            board[i][j]=ch;
                            if(fun(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool check(int row,int col,vector<vector<char>>& board,char ch){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch || board[i][col]==ch){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch){
                return false;
            }
        }
        return true;
    }
};