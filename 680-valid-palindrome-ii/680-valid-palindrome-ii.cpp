class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.length();
        int l=0;
        int r=n-1;
        
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                // cout<<"checking "<<(l+1)<<" "<<r<<"       "<<l<<" "<<(r-1)<<endl;
                return checkPalindrome(s,l+1,r) or checkPalindrome(s,l,r-1);
            }  
        }
        
        return true;
        
    }
    
    bool checkPalindrome(string s, int i, int j){ 
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }return true;
    }
};