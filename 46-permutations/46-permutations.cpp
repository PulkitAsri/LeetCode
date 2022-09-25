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
    
    void solve2(vector<int> &nums, int idx){
        if(idx==nums.size()){
            //basecase-> array is in correct order
            ans.push_back(nums);
        }
        
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i],nums[idx]);
            solve2(nums, idx+1);
            swap(nums[i],nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        // solve(nums,temp, visited);
        solve2(nums,0);
        return ans;
    }
};