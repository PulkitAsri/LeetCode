class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n=s.length();
        for(int i=0; i<n; i+=k){
            if(i+k > n){
                string str=s.substr(i, k-(i+k-n));
                for(int j=0;j< i+k-n ;j++){
                    str=str+fill;
                }
                ans.push_back(str);
            }
            else 
                ans.push_back(s.substr(i,k));
        }
        return ans;
    }
};