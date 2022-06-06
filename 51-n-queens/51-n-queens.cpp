class Solution {
    
    
public:
    vector<vector<string> > ans;
    
    bool isSafe(int x, int y, int &n){
        return x >= 0 && y >= 0 && x<n && y<n;
    }
    
    bool isSafeFromQueen(vector<string> &board, int r, int c){
        int n=board.size();
        for(int i=0; i<n; i++){
            //since we assume row at one row we place only one queen
            // row-> unique;
            //col
            if(board[i][c]=='Q') return false;
            if(isSafe(r-i,c-i,n) && board[r-i][c-i]=='Q') return false;
            if(isSafe(r-i,c+i,n) && board[r-i][c+i]=='Q') return false; 
        }
        return true;
            
    }
    

    void solve(vector<string> &board, int &n, int r){
        if(r==n){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            
            if(isSafeFromQueen(board,r, i)){
                //include the idx and call the next row
                board[r][i]='Q';
                solve(board,n,r+1);

                //exclude the idx and call the next row
                board[r][i]='.';
                // solve(board,n,r+1);
            }
        }
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n,string(n,'.'));
        solve(board,n,0);
        return ans;
        
    }
};