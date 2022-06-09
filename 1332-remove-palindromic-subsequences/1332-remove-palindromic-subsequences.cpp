class Solution {
    bool isPalindrome(string &s){
        int l=0;
        int r=s.length()-1;
        while(l<r) if(s[l++]!=s[r--]) return false;
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if(isPalindrome(s)) return 1;
        else return 2;
    }
};