class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n=num.length();
        
        string ans="";
        int kCopy=k;
        
        for( int i=0; i<n; i++){
            int x=num[i]-'0';
            
            while(!st.empty() && x < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(x);
            
        }  
        
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        ans=ans.substr(0, n-kCopy);
        // cout<<ans;
        
        // removing leading zeoes
        ans.erase(0, ans.find_first_not_of('0'));

        return ans==""?"0":ans;
    }
};