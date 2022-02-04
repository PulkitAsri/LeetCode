class Solution {
    
    string reverseStr(string s){
        reverse(s.begin(),s.end());
        return s;
    }
    
    string invert(string s){
        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        return s;
    }
    
    string func(int n){
        if(n==1) return "0";
        
        string ans=func(n-1);
        
        return ans + "1" +reverseStr(invert(ans));
    }
public:
    char findKthBit(int n, int k) {
        string s=func(n);
        return s[k-1];
    }
};