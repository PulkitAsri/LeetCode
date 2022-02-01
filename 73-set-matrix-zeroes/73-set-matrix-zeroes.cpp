class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // set<pair<int,int>> set;
        int m=matrix.size();
        int n=matrix[0].size();
        
        bool includeFirstRow=false;
        bool includeFirstCol=false;
        
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0) includeFirstRow=true;
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) includeFirstCol=true;
        }
        
        
        //Using First Col And Row As Markers
        // (Since Constant Storage is needed)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            } 
        }
        
        //Using Those Markers to mark zeros       
        for(int i=1; i<m; i++){
            if(matrix[i][0]==0){
                for(int j=1; j<n; j++){
                    matrix[i][j]=0;
                } 
            }
        }  
        
        for(int i=1; i<n; i++){
            if(matrix[0][i]==0){
                for(int j=1; j<m; j++){
                    matrix[j][i]=0;
                } 
            }
        }
        
        //Finally First Row And Col
        
        if(includeFirstRow){
            for(int i=0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        
        if(includeFirstCol){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};