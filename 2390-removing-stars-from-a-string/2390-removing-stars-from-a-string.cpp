class Solution {
public:
    string removeStars(string s) {
        string ans;
        stack<char> st;
        for(char c: s){
            if(c=='*'){
                st.pop();
            }else{
                st.push(c);
            }
        }
        
        while(st.size()!=0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};