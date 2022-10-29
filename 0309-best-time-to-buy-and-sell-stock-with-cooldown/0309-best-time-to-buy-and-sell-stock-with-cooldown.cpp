
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        // return solve(0,true,prices,n);
        
        vector<int> prev2(2,0);
        vector<int> prev(2,0);
        vector<int> curr(2,0);


        for(int i=n+1; i>=0; i--){
            for(int b=0; b<=1; b++){
                
                if(i>=n) curr[b]=0;
                else if(b){
                    int buy= prev[!b] - prices[i];
                    int notBuy= prev[b];
                    curr[b]= max(buy,notBuy);
                    
                }else{
                    int sell= prev2[!b] + prices[i];
                    int notSell= prev[b];
                    curr[b]= max(sell,notSell);
                }
            }
            prev2=prev;
            prev=curr;
        }
        return prev[true];
    }
};