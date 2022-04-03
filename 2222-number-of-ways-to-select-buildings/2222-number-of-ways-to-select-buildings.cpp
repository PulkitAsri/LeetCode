class Solution {
public:
    long long numberOfWays(string s) {
        
        int n=s.length();
        long long totalWays=0;
        int ways=1;
    
        vector<int> sections;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                ways++;
            }else{
                sections.push_back(ways);
                ways=1;
            }
        }
        sections.push_back(ways);
        //sections => 111 00 1 0000 1 0
        //             3   2 1  4   1 1
        int ns=sections.size();
        
        //prefix
        vector<long long> prefix(ns,0ll);
        for(int i=0; i<ns; i++) prefix[i]=sections[i];
        for(int i=ns-3; i>=0; i--){
            prefix[i]+= prefix[i+2];
        }
        
        //precompute
        vector<long long> preCompute(ns,0);
        for(int i=0;i<=ns-2; i++){
            preCompute[i]=prefix[i+1]*sections[i];
        }
        //precompute prefix
        for(int i=ns-3; i>=0; i--){
            preCompute[i]+= preCompute[i+2];
        }
        
        
        
        //Calculating total
        for(int i=0; i<ns-2; i++){
            totalWays+=sections[i]*preCompute[i+1];
        }
        
        return totalWays;
    }
};