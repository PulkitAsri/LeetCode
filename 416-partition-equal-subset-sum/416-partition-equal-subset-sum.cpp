class Solution {

    bool subsetSum(vector<int> &nums, int sum){
        
        int n=nums.size();
        
        bool dp[202][200002];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(i==0) dp[i][j]= false;
                if(j==0) dp[i][j]=true;
            }
        }
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if( nums[i-1] <= j ){
                    //nums[i-1]=> w1 ,  j=>W
                    dp[i][j]= (dp[i-1][j] or dp[i-1][j-nums[i-1]]);
                }else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
        
    }
public:
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        for(int &x:nums) sum+=x;
        
        if(sum%2==1){
            return false;
        }else{
            return subsetSum(nums, sum/2);
        }
    }
};