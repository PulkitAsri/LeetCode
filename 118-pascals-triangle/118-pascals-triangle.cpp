#define ll unlong long int
class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        vector<int> first;
        
        first.push_back(1);
        ans.push_back(first);
        if(n==1) return ans;
        
        first.push_back(1);
        ans.push_back(first);
        if(n==2) return ans;
        
        for (int i = 2; i < n; i++){
            vector<int> temp;
            temp.push_back(1);
            for (int j = 0; j < i-1; j++){
                int x=ans[i-1][j] + ans[i-1][j+1];
                temp.push_back(x);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};