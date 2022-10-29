
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        // return solve(0,true,prices,n);
        
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        for(int i=n+1; i>=0; i--){
            for(int b=0; b<=1; b++){
                
                if(i>=n) dp[i][b]=0;
                else if(b){
                    int buy= dp[i+1][!b] - prices[i];
                    int notBuy= dp[i+1][b];
                    dp[i][b]= max(buy,notBuy);
                    
                }else{
                    int sell= dp[i+2][!b] + prices[i];
                    int notSell= dp[i+1][b];
                    dp[i][b]= max(sell,notSell);
                }
            }
        }
        return dp[0][true];
    }
};