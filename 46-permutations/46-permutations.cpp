class Solution {
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> &curr, vector<bool> &visited){
        if(curr.size()== nums.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                //if free... select and call further
                curr.push_back(nums[i]);
                visited[i]=true;
                solve(nums, curr, visited);
                curr.pop_back();
                visited[i]=false;
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        solve(nums,temp, visited);
        return ans;
    }
};