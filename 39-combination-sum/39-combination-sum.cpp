class Solution {
    void combinationSum(vector<int>& candidates, int sumLeft, vector<vector<int>> &ans, vector<int> &curr, int i ){
        if(sumLeft <0) return;
        if(i==candidates.size()){
            //base case
            if(sumLeft==0){
                ans.push_back(curr);
            }
            return;   
        }
        
        //Take or Not Take
        curr.push_back(candidates[i]);
        combinationSum(candidates, sumLeft-candidates[i], ans, curr, i);
        curr.pop_back();
        combinationSum(candidates, sumLeft, ans, curr, i+1 );
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        combinationSum(candidates, target, ans, temp, 0 );
        return ans;
    }
};