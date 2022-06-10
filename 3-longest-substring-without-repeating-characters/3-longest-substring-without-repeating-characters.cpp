class Solution {
    
    //auxiliary methods 
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
    
    
    //approaches
    //O(n*256)
    int windowingWordLengths(string s) {
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
            for(int i=1; i+w <= n; i++){
                
                mp[s[i-1]]--;
                mp[s[i+w-1]]++;
                bool b=isGood(mp);
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
    
    //O(nLog(256))
    int windowingWithBinarySearch(string s) {
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
        //Queue + map-> O(n)
        return l;
    }
    
    
public:
    int lengthOfLongestSubstring(string s) {
        // return windowingWordLengths(s);
        // return windowingWithBinarySearch(s);
        
        int n=s.length();
        
        queue<char> q;
        vector<bool> mp(256,false);
        int ans=0;
        for(char &c: s){
            if(mp[c]==true){
                while(q.front()!=c) {
                    mp[q.front()]=false;
                    q.pop();
                }
                mp[q.front()]=false;
                q.pop();
            }
            mp[c]=true;
            q.push(c);
            ans= max((int)q.size(), ans);
        }
        return ans;
    }
};