class Solution {
    bool isValid(char &c, int &row, int &col, vector<vector<char>> &board){
        for(int i=0; i<9; i++){
            if(board[row][i]==c) return false;
            if(board[i][col]==c) return false;
        }
        int sqStartRow= 3*(row/3);
        int sqStartCol= 3*(col/3);
            
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[sqStartRow +i ][sqStartCol +j]==c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    
                    for(char c='1'; c<='9'; c++ ){
                        if(isValid(c,i,j, board)){
                            board[i][j]=c;
                            bool success= solve(board); //recc
                            if(success==true){
                                return true; //can be placed here
                            }else{
                                board[i][j]='.'; //remove it as...if put, wont be possible if we go further from here
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};