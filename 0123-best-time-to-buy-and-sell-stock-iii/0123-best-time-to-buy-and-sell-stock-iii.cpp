#include <bits/stdc++.h> 

int dp[100005][3][2];
class Solution {
  public:
    int solve(int i, int buyFreq, bool canBuy, vector<int>& prices, int n){
        if(buyFreq==2) return 0;
        if(i==n) return 0;
        if(dp[i][buyFreq][canBuy]!=-1) return dp[i][buyFreq][canBuy];

        if(canBuy){
            //buying
            int buy= solve(i+1, buyFreq, false, prices,n) - prices[i];
            int notBuy= solve(i+1, buyFreq, true, prices,n);
            return dp[i][buyFreq][canBuy]= max(buy,notBuy);
        }else{
            //Selling
            int sell= solve(i+1, buyFreq + 1, true, prices,n) + prices[i];
            int notSell= solve(i+1, buyFreq, false, prices,n);
            return dp[i][buyFreq][canBuy]= max(sell,notSell);  
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof dp);
        return solve(0,0,true,prices,n);
    }
};