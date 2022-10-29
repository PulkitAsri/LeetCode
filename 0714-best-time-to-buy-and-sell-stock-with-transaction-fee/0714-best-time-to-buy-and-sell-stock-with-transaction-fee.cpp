class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int i=n; i>=0; i--){
            for(int b=0; b<=1; b++){
                if(i==n) dp[i][b]= 0;
                else if(b){
                    int buy= dp[i+1][!b] - prices[i];
                    int nBuy= dp[i+1][b];
                    dp[i][b]= max(buy,nBuy);
                    
                }else{
                    int sell= dp[i+1][!b] + prices[i]- fee;
                    int nSell= dp[i+1][b];
                    dp[i][b]= max(sell,nSell);
                }
            }
        }
        
        return dp[0][true];
    }
};