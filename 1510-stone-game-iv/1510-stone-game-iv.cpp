class Solution {
    vector<bool> winnerAt;
public:
    
    bool winnerSquareGame(int n){
        vector<int> dp(100001,-1);
        return winnerSquareGame(dp, n);
    }
    
    bool winnerSquareGame(vector<int> &dp, int n) {
        
        if(n<=0) return false;
        if(dp[n]!=-1) return dp[n];
        
        bool ans=false;
        
        for(int i=1; i*i<=n; i++){
            if(!winnerSquareGame(dp, n - i*i)){
                ans=true;
                break;
            }
        }
        return dp[n]=ans;
        
    }
};