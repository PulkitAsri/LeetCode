// #include <bits/stdc++.h>
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n= s.size();
        stack<int> st;
        st.push(-1);  
        int x=0;
        int ans=0;
        for(int i=0 ;i<n; i++){
            char c= s[i];
            if(c=='('){
                st.push(i);
            }else if(c==')'){
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans=max(ans, i- st.top());
                }
                
            }
            // cout<<x<<" "<<ans<<endl;
        }
        // cout<<endl;
        return ans;
    }
};