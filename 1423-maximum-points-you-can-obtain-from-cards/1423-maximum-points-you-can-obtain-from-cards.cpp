class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n= cardPoints.size();
        int totalSum=0;
        for(int x: cardPoints) totalSum+=x;
        
        int window=0;
        int w= n-k;
        for(int i=0; i<w; i++){
            window+=cardPoints[i];
        }
        
        int minWindowSum=window;

        
        for(int i=w; i<n; i++){
            window -= cardPoints[i-w];
            window += cardPoints[i];
            minWindowSum= min(window, minWindowSum);
            
        }
        // cout<<minWindowSum<<endl;
        
        return totalSum - minWindowSum;
      
        
    }
};