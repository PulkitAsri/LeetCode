class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int> maxRight(n,0);

        maxRight[n-1]=INT_MIN;
        int currMax=prices[n-1];
        
        for(int i=n-2; i>=0; i--){
            currMax=max(currMax,prices[i]);
            maxRight[i]=currMax;
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(maxRight[i]!=INT_MIN)
                ans=max(ans, maxRight[i]-prices[i]);
        }
        return ans;
    }
};