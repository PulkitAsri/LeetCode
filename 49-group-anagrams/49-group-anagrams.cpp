#define ull unsigned long long
class Solution {
    
    string hash(string s){
        vector<int> freq(26,0);
        int j=0;
        for(char &c:s) freq[c-'a']++;
        for(int i=0; i<26; i++) if(freq[i]!=0) while(freq[i]--) s[j++]=(char)(i+'a');            
        return s;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string ,vector<string>> mp;
        
        for(auto &s:strs){
            string h=hash(s);
            if(mp.count(h)==0) mp[h]={s};
            else  mp[h].push_back(s);
        }
        
        for(auto &p: mp) ans.push_back(p.second);
        
        return ans;   
    }
};