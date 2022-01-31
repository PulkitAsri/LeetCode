class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> set;
        
        int n=s.length();
        int ans=0;
        int st=0,e=0;
        while(e<n){
            
            if(set.count(s[e])==0){
                set.insert(s[e]);
                e++;           
            }else{
                set.erase(s[st]);
                ++st;
            }
            
            ans=max(ans, e-st);
        }
        return ans;     
    }
    
};