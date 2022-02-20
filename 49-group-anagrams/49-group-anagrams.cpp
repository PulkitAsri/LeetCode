#define ull unsigned long long
class Solution {
    
    string hash(string s){
        string k=s;
        sort(k.begin(),k.end()); 
        return k;
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