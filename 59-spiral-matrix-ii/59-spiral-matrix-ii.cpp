class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n,vector<int>(n,0));
        
        int hStart=0;
        int vStart=0;
        int hEnd=n -1;
        int vEnd=n-1 ;
        
        int y=1;
        
        while(vStart <= vEnd && hStart <= hEnd){
            for(int i = hStart ; i <= hEnd  ; i++){
                ans[vStart][i]=y;
                y++;
            }
            vStart++;
            
            for(int i = vStart ; i <= vEnd  ; i++){
                ans[i][hEnd]=y;
                y++;
            }
            hEnd--;
            
            if(vStart > vEnd || hStart > hEnd) break;

            for(int i = hEnd ; i >= hStart  ; i--){
                ans[vEnd][i]=y;
                y++;
            }
            vEnd--;

            for(int i = vEnd ; i >= vStart  ; i--){
                ans[i][hStart]=y;
                y++;
            }
            hStart++;
        }
        
        return ans;
        
    }
};