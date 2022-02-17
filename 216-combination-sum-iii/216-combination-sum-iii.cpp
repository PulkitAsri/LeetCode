class Solution {
    void combinationSum3(int k, int n, int max, vector<vector<int>> &ans, vector<int> &curr){
        
        if(n < 0) return;
        
        if(max==0){
            if(n==0 && k==0) ans.push_back(curr);
            return;
        }
        
        curr.push_back(max);
        combinationSum3(k-1, n-max, max-1, ans, curr);
        curr.pop_back();
        combinationSum3(k, n, max-1, ans, curr);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        combinationSum3(k,n,9,ans,curr);
        return ans;
        
    }
};