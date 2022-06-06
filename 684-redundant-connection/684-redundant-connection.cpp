class Solution {
    vector<int> parent;
    vector<int> rank;
    
    int Find(int x){
        if(parent[x]!=x) parent[x]=Find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        int xParent= Find(x);
        int yParent= Find(y);
        
        if(xParent == yParent) return;
        
        if(rank[xParent] < rank[yParent]){
            parent[xParent] = yParent;
        } else if(rank[xParent] > rank[yParent]){
            parent[yParent]=xParent;
        } else {
            parent[yParent]=xParent;
            rank[xParent]++;
        }
        
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent= vector<int>(n+1, -1);
        rank= vector<int>(n+1,1);
        
        for(int i=1; i<=n; i++){
            parent[i]=i;
            rank[i]=1;
        }
        
        for(auto edge: edges){
            if(Find(edge[0])==Find(edge[1])){
                return edge;
                break;
            }else{
                Union(edge[0],edge[1]);
            }
        }
        
        return edges[n-1];
    }
};