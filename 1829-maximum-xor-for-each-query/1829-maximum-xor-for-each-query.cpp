class Solution {
    
    int flipBits(int f, int maxB){
        return f^((1<<maxB)-1);
    }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> ans;
        
        // xor of all
        int all=0;
        for(int x:nums){
            all=all^x;
        }
        
        // queries
        for(int i=0;i<n;i++){
            ans.push_back(flipBits(all, maximumBit));
            all=all^nums[n-1 -i];
        }
        return ans;
    }
};