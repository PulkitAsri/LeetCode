class Solution {
    void combinationSum(vector<int>& candidates, int sumLeft, vector<vector<int>> &ans, vector<int> &curr, int idx ){
        if(sumLeft < 0) return;

        //base case
        if(sumLeft==0){
            ans.push_back(curr);
            return;

        }
        
        for(int i=idx; i<candidates.size(); i++){
            if( i > idx && candidates[i] == candidates[i-1] ) continue; //skip same cases
            if(candidates[i] > sumLeft) break; //since it is exceeded and in an asc sorted order, no further calls needed
            
            curr.push_back(candidates[i]);
            combinationSum(candidates, sumLeft-candidates[i], ans, curr, i+1);
            curr.pop_back();
            
        }
        //Take or Not Take
        
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, ans, temp, 0 );
        
        return ans;
        // return vector<vector<int>> (st.begin(), st.end());
//         vector<vector<int>> finalAns (st.begin(), st.end());

//         return finalAns;
    }
};