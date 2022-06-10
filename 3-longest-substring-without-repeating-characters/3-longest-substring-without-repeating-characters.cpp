class Solution {
    bool isGood(map<char,int> &mp){
        for(auto &p: mp){
            if ( p.second > 1 ) return false;
        }
        return true;
    }
    bool isGoodSubstring(string &s, int &w){
        map<char,int> mp;
        int n=s.length();
        
        bool flag=false;
        if(w<=1) return true;
        for(int i=0; i<w; i++) mp[s[i]]++;
        if(isGood(mp)){ 
            flag=true;
        }
        // cout<<s.substr(0,w)<<" "<<endl;
        for(int i=1; i+w <= n; i++){

            mp[s[i-1]]--;
            mp[s[i+w-1]]++;
            bool b=isGood(mp);
            // cout<<w<<" "<<s.substr(i,w)<<" "<<b<<endl;;
            if(b){ 
                flag=true;
                break;
            }
        }
        return flag;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=0;
        int w=min(n,256);
        
        
        int l=0;
        int r=w+1;
        
        while(r-l > 1){
            int m= (l+r)/2;
            if(isGoodSubstring(s,m)){
                l=m;
            }else{
                r=m;
            }
        }
        
        return l;
    }
};