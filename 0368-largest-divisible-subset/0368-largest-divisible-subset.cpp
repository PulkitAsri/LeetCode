class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> seq;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> path(n,0);
        int ans=1;
        int lastIdx=0;
        for(int i=1; i<n; i++){
            path[i]=i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i]= dp[j]+1;
                    // set path
                    path[i]=j;
                    
                }
            }
            if(dp[i] > ans){
                ans=dp[i];
                lastIdx=i;
            }
        }
        // cout<<ans<<endl;
        // cout<<lastIdx<<endl<<endl;
        int p= lastIdx;
        seq.push_back(nums[lastIdx]);
        while(p!=path[p]){
            p= path[p];
            seq.push_back(nums[p]);
            
        }
        reverse(seq.begin(), seq.end());
        return seq;
    }
};