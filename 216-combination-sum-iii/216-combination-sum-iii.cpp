class Solution {
    void recurr(vector<vector<int>> &ans,  vector<int> &temp, int k, int n, int i){
        if(i==10){
            if(k==0 && n==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(k==0){
            if(n==0){
                ans.push_back(temp);
            }
            return;
        }
        
        temp.push_back(i);
        recurr(ans, temp, k-1, n-i, i+1);
        temp.pop_back();
        recurr(ans, temp, k, n, i+1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum=0;
        recurr(ans,temp,k,n,1);
        return ans;
        
    }
};