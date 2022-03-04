class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // if(poured >=100) return 1.0;
        
        double p= poured;
        vector<vector<double>> glasses(100,vector<double>(100,0));
        
        glasses[0][0]=p;
        
        for(int i=1; i<100; i++){
            bool flag=0;
            for(int j=0; j<=i; j++){
                double x=glasses[i-1][j];
                flag|= x!=0 ;
                if(x >= 1){
                    glasses[i][j]+= ((x-1)/2);
                    glasses[i][j+1]+= ((x-1)/2);
                    glasses[i-1][j]=1;
                }
                // cout<<glasses[i][j]<<" ";    
            }
            // cout<<endl;
            if(flag==0) break;
        }
        // cout<<"\n\n";
        return glasses[query_row][query_glass];
        
        
    }
};