class Solution {
    bool checkZeroes(vector<int> &freq){
        for(int i=0;i<26;i++)
            if(freq[i]!=0)
                return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n= s.length();
        int k=p.length();
        vector<int> ansIdxs;
        
        vector<int> freq(26,0);
        for(char c:p){
            freq[c-'a']++;
        }
        
        for(int i=0; i<=n-k; i++){
            
            vector<int> copy=freq;
            for(int j=0; j < k; j++){
                copy[s[i+j]-'a']--;
            }
            
            if(checkZeroes(copy)){
                ansIdxs.push_back(i);
            }  
        }
        return ansIdxs;
    }
};