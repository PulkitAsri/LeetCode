class Solution {
    bool isValid(vector<vector<int>> &graph, vector<int> &gardenFlowerTypes, int idx, int color){
        
        for(int neighbour: graph[idx]){
            if (gardenFlowerTypes[neighbour]==color) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<int>> &graph, int &n, vector<int> &gardenFlowerTypes, int idx){
        if(idx==n) return true;
        
        for(int i=1; i<=4; i++){
            if(isValid(graph, gardenFlowerTypes, idx, i)){
                gardenFlowerTypes[idx]=i;
                bool success= solve(graph, n, gardenFlowerTypes, idx+1);
                if(success){
                    return true;
                }else{
                    gardenFlowerTypes[idx]=-1;
                }
            }
        }
        return false;
        
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        vector<int> gardenFlowerTypes(n,-1);
        //constructing the graph
        for(auto &path: paths ){
            int x=path[0]-1;
            int y=path[1]-1;
            
            graph[x].push_back(y);
            graph[y].push_back(x); 
        }
        
        solve(graph, n, gardenFlowerTypes, 0);
        return gardenFlowerTypes;
        
        
    }
};