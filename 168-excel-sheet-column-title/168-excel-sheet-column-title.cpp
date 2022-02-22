class Solution {
public:
    string convertToTitle(int c) {
        
        string ans="";
        
        while(c ){
            c--;
            int x=c%26;
            ans+=(char)(x +'A');
            c/=26;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
};