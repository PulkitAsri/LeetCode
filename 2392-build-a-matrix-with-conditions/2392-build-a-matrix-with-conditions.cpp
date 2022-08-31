class Solution {
    
    vector<int> topoSort(int k, vector<vector<int>> &edges){
        vector<vector<int>> dag(k+1,vector<int>());
        vector<int> inDegree(k+1,0);
        
        vector<int> topoSort;
        for(auto &edge: edges){
            dag[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
//         for(int i=1;i<=k; i++){
//             cout<<i<<"->   ";
            
//             for(int x: dag[i]){
//                 cout<<x<<", ";
//             }
//             cout<<endl;
//         }
    
        queue<int> q;
        // Find All the nodes with indegree 0 (find all the sources for the bfs)
        for(int i=1; i<=k; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int x= q.front();
            q.pop();
            topoSort.push_back(x);
            
            //now remove the node from the dag (hypothetically in terms of indegree)
            for(int i: dag[x]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
        
        return topoSort.size()==k ? topoSort: vector<int>();
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        auto rowTopoSort= topoSort(k, rowConditions);
        auto colTopoSort= topoSort(k, colConditions);
        
//         for(int i: rowTopoSort) cout<<i<<" "; cout<<endl;
//         for(int i: colTopoSort) cout<<i<<" "; cout<<endl;
        
        if(rowTopoSort.size() ==0 or colTopoSort.size() ==0 ) return vector<vector<int>>();
        
        vector<pair<int,int>> cood(k+1 ,{-1,-1});
        
        for(int i=0; i<k; i++){
            cood[rowTopoSort[i]].first = i;
            cood[colTopoSort[i]].second = i;
        }
        
        vector<vector<int>> ans(k, vector<int>(k));
        
        for(int i=1; i<=k; i++){
            auto [x,y]= cood[i];
            ans[x][y]= i;
        }
        
        return ans;
        

        
    }
};