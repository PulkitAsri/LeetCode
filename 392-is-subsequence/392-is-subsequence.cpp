class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen=s.length();
        int tLen=t.length();
        
        int sp=0;
        int tp=0;
        
        while(sp < sLen && tp < tLen){
            if(s[sp]==t[tp]){
                sp++;
                tp++;
            }else tp++;
        }
        
        return sp==sLen;
    }
};