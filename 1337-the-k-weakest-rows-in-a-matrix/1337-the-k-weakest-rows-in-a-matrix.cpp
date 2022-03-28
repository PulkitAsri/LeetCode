bool compareWeak(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> sols(m);
        for(int i=0; i<m; i++){
            int s=0;
            for(int j=0; j<n; j++){
                s+=mat[i][j];
            }
            sols[i]={s,i};
        }
        
        sort(sols.begin(),sols.end(),compareWeak);
        
        vector<int> ans(k,0);
        
        for(int i=0; i<k; i++){
            ans[i]=sols[i].second;
        }
        
        return ans;
    }
};