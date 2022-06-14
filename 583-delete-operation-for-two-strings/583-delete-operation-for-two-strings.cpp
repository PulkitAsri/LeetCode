class Solution {
    
    int dp[502][502];
public:
    int lcs(string &word1,  string &word2, int n, int m){
        
        if(n==0 or m==0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(word1[n-1]==word2[m-1]){
            return dp[n][m]= 1 + lcs(word1, word2, n-1, m-1);
        }else{
            dp[n][m-1] = lcs(word1, word2, n, m-1);
            dp[n-1][m] = lcs(word1, word2, n-1, m);
            return max(dp[n-1][m],dp[n][m-1]);
        }
    }
    
    int minDistance(string word1, string word2) {
        
        int n= word1.length();
        int m= word2.length();
        memset(dp, -1, sizeof(dp));
        int longestCommonSubsequence= lcs(word1, word2, n, m);
        
        return m+n - 2*longestCommonSubsequence;
    }
};