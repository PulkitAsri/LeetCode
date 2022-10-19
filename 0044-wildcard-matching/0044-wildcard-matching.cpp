
class Solution {
    int dp[2002][2002];
public:
    bool solve(int i, int j, string &s, string &t){
        int &ans = dp[i+1][j+1];
        if(ans!=-1) return ans;
        
        if(i<0 and j<0) return ans= true;
        if(j<0) return ans= false;
        if(i<0){
            return ans= t[j]=='*' && solve(i,j-1,s,t);
        } 
         
        if(s[i]==t[j]){
            //match
            return ans= solve(i-1,j-1,s,t);
        }else{
            if(t[j]=='*'){
                //either process it and stay or exit the star
                return ans= solve(i-1,j,s,t) or solve(i,j-1,s,t);
            }else if (t[j]=='?'){
                return ans= solve(i-1,j-1,s,t);
            }else return ans= false;
        }
    }
    bool isMatch(string s, string t) {
        int n= s.length();
        int m= t.length();
        // memset(dp,-1,sizeof dp);
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j]=-1;
            }
        }
        
        return solve(n-1,m-1,s,t);
    }
};