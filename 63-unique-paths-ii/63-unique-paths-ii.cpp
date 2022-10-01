class Solution {
    bool isSafe(int i, int j, vector<vector< int>> &mat) {
        return i>=0 && j>=0 && mat[i][j]!=1;
    }
public:
    int dp[102][102];
    int solve(int i, int j, vector< vector< int> > &maze) {
        if(!isSafe(i,j,maze)) return 0;
        if(i==0 && j == 0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = isSafe(i-1,j,maze) ? solve(i-1,j,maze) :0;
        int left = isSafe(i,j-1,maze) ? solve(i,j-1,maze): 0;

        return dp[i][j]= up+left;

    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& maze) {
        // memset(dp,-1, sizeof dp);
        int m= maze.size();
        int n= maze[0].size();
    
        // return solve(m-1,n-1, obstacleGrid);
        
        //ITERATIVE
        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if(!isSafe(i,j,maze)) dp[i][j]=0;
                else if(i==0 and j==0) dp[i][j]=1;
                else{
                    int up = isSafe(i-1,j,maze) ? dp[i-1][j]: 0;
                    int left = isSafe(i,j-1,maze) ? dp[i][j-1]: 0;

                    dp[i][j]= up + left;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};