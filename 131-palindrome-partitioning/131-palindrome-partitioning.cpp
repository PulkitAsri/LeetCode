class Solution {
    bool isPalindrome(string s){
        string s1=s;
        reverse(s1.begin(),s1.end());
        return s1==s;
    }
    
    void partition(string &s, int &n, vector<vector<string>> &ans, vector<string> &curr, int idx){
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx; i<n; i++){
            string sub= s.substr(idx,i-idx+1);
            if(isPalindrome(sub)){
                //Add and Further call
                curr.push_back(sub);
                partition(s,n,ans,curr,i+1);
                curr.pop_back();
            }
        }
        
        
    }
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.length();
        // cout<<isPalindrome("abba")<<endl;
        // cout<<isPalindrome("abbb")<<endl;

        partition(s,n,ans,temp,0);
        return ans;
        
        
    }
};