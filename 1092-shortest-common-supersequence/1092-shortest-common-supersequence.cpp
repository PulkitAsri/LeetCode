#include <bits/stdc++.h> 
int dp[1002][1002];

class Solution {

public: 
    string shortestCommonSupersequence(string s, string t) {
        int n =s.length();
        int m =t.length();

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else{
                    if(s[i-1]==t[j-1]){
                        dp[i][j]= 1 + dp[i-1][j-1];
                    }else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }

            }
        }

        int lcs= dp[n][m];
    //     cout<< (n+m -lcs)<<endl ;
        
        
        string ans="";
        int i=n,j=m;

        while(i>0 or j>0){
            if(i==0) {
                ans+=t[j-1]; j--;
            }
            else if (j==0) {
                ans+=s[i-1]; i--;
            }
            
            else if(s[i-1]==t[j-1]){
                ans+=s[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans+=s[i-1];
                    i--;
                }else{
                    ans+=t[j-1];
                    j--;
                }
            } 
        }

        // if(i!=0) ans+=s[i-1];
        // else if(j!=0) ans+=t[j-1];

        reverse(ans.begin(), ans.end());

        return ans;
    }
};