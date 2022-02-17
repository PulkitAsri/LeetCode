class Solution {
    void combinationSum(vector<int>& arr, int sum, vector<vector<int>> &ans, int idx, vector<int> &curr){
        
        if(sum < 0) return;
        if(idx==arr.size()){
            if(sum==0) ans.push_back(curr);
            return;
        }
        
        curr.push_back(arr[idx]);
        combinationSum(arr, sum-arr[idx], ans, idx, curr);
        
        curr.pop_back();
        combinationSum(arr, sum, ans, idx+1, curr);
        
        
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        combinationSum(candidates, target, ans, 0, temp);
        return ans;
        
    }
};