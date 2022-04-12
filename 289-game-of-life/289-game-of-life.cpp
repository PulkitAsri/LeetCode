class Solution {
    bool isSafe(int &i, int &j, int &n, int &m){
        return i<n && j<m && i>=0 && j>=0;
    }
    
    int countNeighbours(vector<vector<int>>& board, int &i, int &j, int &n, int &m){
        vector<int> dx={0,0,1,-1,1,1,-1,-1};
        vector<int> dy={1,-1,0,0,1,-1,-1,1};
        int count =0;
        
        for(int v=0 ;v<8; v++){
            int x=i + dx[v];
            int y=j + dy[v];
            
            if(isSafe(x,y,n,m)){
                if(board[x][y]==1) count++;
                // cout<<"("<<x<<","<<y<<")";
                // cout<<"->safe   ";
            }
        }
        
        // cout<<endl;
        return count;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m= board[0].size();
        
        vector<vector<int>> neigh(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                neigh[i][j]= countNeighbours(board,i,j,n,m);
                // cout<<neigh[i][j]<<endl;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x= neigh[i][j];
                // cout<<"("<<i<<","<<j<<") ";
                // cout<<x<<endl;
                if(x<2){
                    board[i][j]=0;
                }else if(x == 2){
                    //do nothing
                }else if(x == 3){
                    if(board[i][j]==0) board[i][j] = 1;
                }else{
                    board[i][j]=0;
                }
            }
        }
    }
};