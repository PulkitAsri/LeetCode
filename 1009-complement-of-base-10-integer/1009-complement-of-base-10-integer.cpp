class Solution {
public:
    int bitwiseComplement(int n) {
        int i=0,nn=n;
        int ans=1;
        
        while(nn>0){ 
            nn=nn>>1;
            if(nn!=0)
                ans=ans<<1;
        }
        ans=ans<<1;
        
        return n^(ans-1);
    }
};