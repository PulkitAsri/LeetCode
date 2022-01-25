#define ll long long
class Solution {
    ll helper(vector<vector<int>>& questions, int n, int index, vector<ll> &dp ){
        if(index >= n) return 0;
        
        if(dp[index]!=0) return dp[index];
        
        int marks=questions[index][0];
        int nextJump=index + questions[index][1] + 1;
        
        
        ll include=questions[index][0] + helper(questions,n,nextJump,dp);
        ll exclude=helper(questions,n,index + 1,dp);
        
        return dp[index]=max(include,exclude);
        
    }
public:
    ll mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        ll maxSum=0;
        
        vector<ll> dp(n,0);
        maxSum=helper(questions,n,0,dp);
  
        return maxSum;
    }
};