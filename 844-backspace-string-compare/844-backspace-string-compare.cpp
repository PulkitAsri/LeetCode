class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a;
        stack<char> b;
        
        for(char &c: s){
            if(c=='#'){
                if(!a.empty()) a.pop();
            }else{
                a.push(c);
            }
            // cout<<a.top()<<endl;
        }
        // cout<<endl;
        for(char &c: t){
            if(c=='#'){
                if(!b.empty()) b.pop();
            }else{
                b.push(c);
            }
            // cout<<b.top()<<endl;
        }
        
        if(a.size()!=b.size()) return false;
        
        while(!a.empty() && !b.empty()){
            if(a.top()!=b.top()) return false;
            a.pop();
            b.pop();
        }
        
        return true;
    }
};