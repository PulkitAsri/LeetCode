class Solution {
    
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        vector<bool> vis(n+1,false);
        
        for(int i=0; i<n; i++){
            fill(vis.begin(),vis.end(),false);
            for(int j=0; j<n; j++){
                if(vis[matrix[i][j]]) return false;
                
                vis[matrix[i][j]]=true;
            }
        }
        fill(vis.begin(),vis.end(),false);
        for(int i=0; i<n; i++){
            fill(vis.begin(),vis.end(),false);
            for(int j=0; j<n; j++){
                if(vis[matrix[j][i]]) return false;
                
                vis[matrix[j][i]]=true;
            }
        }
        
        return true;
    }
};