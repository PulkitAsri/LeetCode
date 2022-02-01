class Solution {
    
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        //for Each Layer
        for(int j=0; j< n/2; j++){
            
            int X[]={j,j,n-1-j,n-1-j};
            int Y[]={j,n-1-j,n-1-j,j};
            
            for(int q=0; q < n-2*j-1 ; q++){
                
                int o=X[0] + q*dx[0];
                int p=Y[0] + q*dy[0];
                int o1,p1;
                
                int temp=matrix[o][p];
                for(int i=3; i>0; i--){
                    o1=X[i] + q*dx[i];
                    p1=Y[i] + q*dy[i];
                                        
                    matrix[o][p]=matrix[o1][p1];
                    o=o1;
                    p=p1;  
                }
                matrix[o][p]=temp;
                
            }
        }  
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};