class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mp;
        mp['}']='{';
        mp[')']='(';
        mp[']']='[';
        
        for(char c: s){
            if(c =='(' || c=='[' || c=='{'){
                st.push(c);
            }else {
                if(st.empty()){
                    return false;
                }else{
                    if(st.top() == mp[c]){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        
        return st.empty();
    }
};