class Solution {
public:
    int count= 0;
    bool isSafe(int x, int y, int &n){
        return x>=0 && y>=0 && x<n && y<n;
    }
    
    bool isSafeFromQueen(vector<vector<bool>> &board, int r, int c){
        int n= board.size();
        
        for(int i=0; i<n; i++){
            //making sure each row has one queen
            //column danger
            if(board[r][i]==true) return false;
            if(isSafe(r-i,c-i,n) && board[r-i][c-i]== true) return false;
            if(isSafe(r+i,c-i,n) && board[r+i][c-i]== true) return false;
            
        }
        return true;
    }
    void solve(vector<vector<bool>> &board, int r){
        int n= board.size();
        
        if(r==n){
            count++;
            return;
        }else{
            for(int i=0 ;i<n; i++){
                //for each cell in a row
                if(isSafeFromQueen(board, i, r)){
                    //place the queen and call the next row
                    board[i][r]=true;
                    solve(board,r+1);
                    
                    //for backtracking remove the queen(for next cell)
                    board[i][r]=false;
                    
                }
                
            }
        }
        
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,false));
        count=0;
        solve(board,0);
        return count;
    }
};