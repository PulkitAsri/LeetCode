class Solution {
    bool isGood(map<char,int> &mp){
        for(auto &p: mp){
            if ( p.second > 1 ) return false;
        }
        return true;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=0;
        int w=min(n,256);
        
        while(w){
            map<char,int> mp;
            bool flag=false;
            for(int i=0; i<w; i++) mp[s[i]]++;
            if(isGood(mp)){ 
                ans=w;
                flag=true;
                break;
            }
            // cout<<s.substr(0,w)<<" "<<endl;
            for(int i=1; i+w <= n; i++){
                
                mp[s[i-1]]--;
                mp[s[i+w-1]]++;
                bool b=isGood(mp);
                // cout<<w<<" "<<s.substr(i,w)<<" "<<b<<endl;;
                if(b){ 
                    ans=w;
                    flag=true;
                    break;
                }
            }
            if(flag) return ans;
            w--;
        }
        return ans;
    }
};