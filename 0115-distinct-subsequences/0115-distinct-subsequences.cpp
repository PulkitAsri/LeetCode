int dp[1002][1002];
class Solution {
public:
    int solve(string &t, string &s, int i, int j){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t[i]==s[j]){
            //to choose or not to choose that is the question 
            return dp[i][j]= solve(t,s,i-1,j-1) + solve(t,s,i-1,j);
        }else{
            return dp[i][j]= solve(t,s,i-1,j);
        }
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof dp);
        int n=s.length();
        int m=t.length();
        
        return solve(s,t,n-1,m-1);
    }
};