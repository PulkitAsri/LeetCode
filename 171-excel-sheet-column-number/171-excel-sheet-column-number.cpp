class Solution {
public:
    int titleToNumber(string s) {
        int n= s.size();
        int ans=0;
        long x=1;
        for (int i=n-1; i>=0; i--){
            ans+=(s[i]-'A' +1)*x;
            x*=26;
        }    
        return ans;
    }
};