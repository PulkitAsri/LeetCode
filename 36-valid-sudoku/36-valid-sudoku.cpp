class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> numSet(10,false);
        
        //Checking all the rows
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                if(numSet[board[i][j]-'0'] == true) return false;
                else numSet[board[i][j]-'0'] = true;
                
            }
            for(int j=1; j<=9; j++) numSet[j]=false;
            // fill(numSet.begin(), numSet.end(), false);
        }
        
        //Checking all the cols
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[j][i]=='.') continue;
                if(numSet[board[j][i]-'0'] == true) return false;
                else numSet[board[j][i]-'0'] = true;
            }
            fill(numSet.begin(), numSet.end(), false);
        }
        
        // Checking all the boxs
        for(int k=0; k<7; k+=3){
            for(int l=0; l<7; l+=3){
                
                //All (k,l) The Starting Points
                
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        int x= k+i;
                        int y= l+j;
                        
                        if(board[x][y]=='.') continue;
                        
                        if(numSet[board[x][y] -'0']) return false;
                        else numSet[board[x][y] - '0'] = true;
                        
                        
                    }
                }
                
                fill(numSet.begin(), numSet.end(), false); 
            }
        }
        
        return true;
    }
};