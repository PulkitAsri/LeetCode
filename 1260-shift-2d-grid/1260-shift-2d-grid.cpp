class Solution {
    
    void shiftGridByOne(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        
        int x1=-1;
        int x2=-1;
        
        for(int i=0; i<n; i++){
            x2=grid[i][m-1];
            for(int j=m-1; j>0; j--){
                grid[i][j]= grid[i][j-1];
            }
            grid[i][0]=x1;
            x1=x2;
        }
        grid[0][0]=x1;
    }
    
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        for(int i=0; i<k; i++){
            shiftGridByOne(grid);
        }
        
        return grid;
    }
};