class Solution {
    void dfs(int s, int &source, vector<vector<int>> &g, vector<int> &ans, vector<bool> &visited){
        if(visited[s]) return;
        
        visited[s]=true;
        for(int i=0; i< g[s].size(); i++ ){  
            
            dfs(g[s][i], source, g, ans, visited);
        }
        if(s!=source)
            ans.push_back(s);        
        return;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int n_edges=edges.size();
        vector<vector<int>> g(n);
        for(int i=0; i<n_edges; i++){
            int u= edges[i][0];
            int v= edges[i][1];
            
            g[v].push_back(u);
        }
        vector<vector<int>> ans(n);
        for(int i=0; i<n; i++){
            vector<bool> visited(n,0);
            bool flag=1;
            dfs(i, i, g, ans[i], visited);
            sort(ans[i].begin(), ans[i].end());
        } 
        return ans;
    }
};

// return result set