int dp[2002][2002];
class Solution {
public:
    bool solve(int i, int j, string &s, string &t){
        
        int &ans = dp[i+1][j+1];
        if(ans!=-1) return ans;
        
        ans = false;
    
        if(i<0 and j<0) 
            ans= true;
        else if(j<0) 
            ans= false;
        else if(i<0) 
            ans = t[j] =='*' && solve(i,j-1,s,t);
        else if(s[i]==t[j]){
            //match
            ans= solve(i-1,j-1,s,t);
        }else{
            if(t[j]=='*'){
                //either process it and stay or exit the star
                ans = solve(i-1,j,s,t) or solve(i,j-1,s,t);
            }else if (t[j]=='?'){
                ans = solve(i-1,j-1,s,t);
            }
        }
        
        return ans;
    }
    bool isMatch(string s, string t) {
        int n= s.length();
        int m= t.length();
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j]=-1;
            }
        }
        
        return solve(n-1,m-1,s,t);
    }
};