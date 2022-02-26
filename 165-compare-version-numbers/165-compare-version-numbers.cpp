class Solution {
    vector<int> parseString(string pString){
        string s="";
        int n=pString.length();
        vector<int> ans;
        for(int i=0; i<n; i++){
            char c=pString[i];
            if(c=='.'){
                ans.push_back(stoi(s));
                // cout<<ans.back()<<endl;
                s="";
            }else
                s+=c;
        }
        ans.push_back(stoi(s));
        // cout<<ans.back()<<endl;
        return ans;
        
    }
    
public:
    int compareVersion(string version1, string version2) {
        auto v1=parseString(version1);
        auto v2=parseString(version2);
        
        int m=min(v1.size(),v2.size());
        int i;
        
        for(i=0; i<m; i++){
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
        }
        if(v1.size()==m){
            for(int j=i; j<v2.size(); j++){
                if(v2[j]!=0) return -1;
            }
        }else{
            for(int j=i; j<v1.size(); j++){
                if(v1[j]!=0) return 1;
            }
        }
        
        return 0;

    }
};