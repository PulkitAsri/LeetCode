class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        vector<bool> all(pow(2,k), false);
        
        if(n <= k) return false;
        long long window= 0;
        for(int i=0; i<k; i++){
            window= window<<1;
            window+= s[i]-'0'; 
        }
        // cout<<window<<" ";
        all[window]=true;
        
        for(int i=k; i<n; i++){
            window= window<<1;
            window &= ~(1<<k);
            window+= s[i]-'0';
            // cout<<window<<" ";
            all[window]=true;
        }
        
        
        for(int i=0 ;i<all.size(); i++){
            if(all[i]==false) return false;
        }
        return true;
    }
};