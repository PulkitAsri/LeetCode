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
        
        if(n<k) return ansIdxs;
        
        vector<int> freq(26,0);
        for(char c:p) freq[c-'a']++;
        
        //Computing the window 1 time ....Then will Update the window
        for(int j=0; j < k; j++){
            freq[s[j]-'a']--;
        }
        if(checkZeroes(freq)){
            ansIdxs.push_back(0);
        }
        
        for(int i=1; i<=n-k; i++){  
            //Using Window Method
            freq[s[i-1] - 'a']++;
            freq[s[i+k-1] - 'a']--;
            
            if(checkZeroes(freq))
                ansIdxs.push_back(i);  
        }
        return ansIdxs;
    }
};