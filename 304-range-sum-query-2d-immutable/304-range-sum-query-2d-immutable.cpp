class NumMatrix {
public:
    vector<vector<int>> prefixMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        prefixMatrix=vector(m,vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            int prefix=0;
            for(int j=0; j<n; j++){
                prefix+= matrix[i][j];
                prefixMatrix[i][j]= prefix;
            }
        }
        
        for(int j=0; j<n; j++){
            int prefix=0;
            for(int i=0; i<m; i++){
                prefix+= prefixMatrix[i][j];
                prefixMatrix[i][j]= prefix;
            }
        }
        
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<prefixMatrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a= prefixMatrix[row2][col2];
        int b= (row1-1 < 0)? 0: prefixMatrix[row1-1][col2];
        int c= (col1-1 < 0)? 0: prefixMatrix[row2][col1-1];
        int d= (row1-1 < 0 or col1-1 < 0 )? 0 : prefixMatrix[row1-1][col1-1];
        // int d=0;
        
        return a-b-c+d;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */