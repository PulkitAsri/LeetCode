class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0;
        
        int n1=0,n2=0;
        
        for(int i=0; i<n; i++){   
            int l=bank[0].length();
            
            for(int j=0; j<l; j++)
                n2+= bank[i][j] - '0';
            
            if(n2==0) continue;
            else{
                ans+=(n1*n2); 
                n1=n2;
                n2=0;
            }
        }
        return ans;
    }
};