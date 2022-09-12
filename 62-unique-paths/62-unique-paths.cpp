class Solution {
    int uniquePaths(vector<vector<int>> &dp, int i, int j, int &m, int &n){
        if(i==m || j==n) return dp[i][j]= 0;
        if(i==m-1 || j==n-1) return dp[i][j]= 1;
        
        int right=dp[i][j]==-1? dp[i+1][j]= uniquePaths(dp,i+1,j,m,n): dp[i+1][j];
        int down= dp[i][j]==-1? dp[i][j+1]= uniquePaths(dp,i,j+1,m,n): dp[i][j+1];
        
        return right + down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n,-1));
        return uniquePaths(dp,0,0,m,n);
    }
};