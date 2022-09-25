class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, vector<int>& curr, int idx){
        ans.push_back(curr);
        for(int i= idx; i< nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            solve(nums, curr, i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, temp, 0);
        return ans;
        
    }
};