class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<int,string> mp;
        set<string> st;
        
        vector<string> words;
        
        int wl=s.length();
        int n=pattern.length();
        
        
        // Splitting into words
        int initIndex=0;
        int finalIndex=0;
        for(int i=0;i<=wl;i++){
            if(s[i]==' ' ){
                words.push_back(s.substr(initIndex, finalIndex-initIndex));
                initIndex=i+1;
                finalIndex=i+1;
            }else if(s[i]=='\0'){
                words.push_back(s.substr(initIndex, finalIndex-initIndex));
                break;
            }else{
                finalIndex++;
            }
        }
        
        if(n!=words.size()) return false;

        // Checking Pattern
        for(int i=0;i<n;i++){
            char c=pattern[i];
            if(mp.count(c-'a')==0){
                //not found
                if(st.count(words[i])==0){
                    mp[c-'a']=words[i];
                    st.insert(words[i]);
                }
                else 
                    return false;
                
                
            }else{
                //found
                if(mp[c-'a']!=words[i])
                    return false;
            }
        }
        
        return true;
    }
    
};