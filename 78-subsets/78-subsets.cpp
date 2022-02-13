class Solution {
    
    void func(int idx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
        
        if(idx==nums.size()){ 
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[idx]);
        func(idx+1, nums, temp, ans);
        
        temp.pop_back(); 
        func(idx+1, nums, temp, ans);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        func(0, nums, temp, ans);
        
        return ans;
        
    }
};