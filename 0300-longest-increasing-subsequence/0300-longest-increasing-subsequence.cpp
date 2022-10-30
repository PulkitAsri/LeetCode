class Solution {
public:
    int solve(int i, int pi,vector<int>& nums, int n, vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];
        
        if(pi == -1 or (pi!=-1 && nums[i] > nums[pi])){
            int take= 1 + solve(i+1,i,nums, n,dp);
            int notTake= solve(i+1,pi,nums, n,dp);
            return dp[i][pi+1]= max(take, notTake);
        }else{
            return dp[i][pi+1]= solve(i+1,pi,nums,n,dp);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(2, vector<int>(n+2,-1));
        // return solve(0,-1,nums,n,dp);
        
        for(int i=n; i>=0; i--){
            for(int pi = n; pi>=0; pi--){
                if(i==n) dp[i%2][pi] = 0;
                else if(pi == 0 or ( nums[i] > nums[pi-1])){
                    int take= 1 + dp[(i+1)%2][i+1];
                    int notTake= dp[(i+1)%2][pi];
                    dp[i%2][pi]= max(take, notTake);
                }else{
                    dp[i%2][pi]= dp[(i+1)%2][pi];
                }
            }
        }
        
        return dp[0][0];

    }
};