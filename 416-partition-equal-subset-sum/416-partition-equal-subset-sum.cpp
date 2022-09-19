int dp[202][20002];
class Solution {
    bool canPartition(vector<int> &nums, int idx, int sum){
        if(sum==0) return true;
        if(idx==0) return false;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        if(nums[idx-1] <= sum){
            return dp[idx][sum]= canPartition(nums,idx-1,sum) or canPartition(nums,idx-1,sum-nums[idx-1]);
        }else return dp[idx][sum]= canPartition(nums, idx-1, sum);
        
        
    }
public:
    bool canPartition(vector<int>& nums) {
        memset(dp,-1, sizeof dp);
        int sum = 0; 
        int n= nums.size();
        for(int x: nums) sum+=x;
        if(sum%2==1) return false;
        return canPartition(nums, n, sum/2);
    }
};

  // 0. 1. 2. 3. 4. 5  
// 0 T
// 1
// 2
// 3
