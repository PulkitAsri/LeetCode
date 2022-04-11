class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(auto &s:ops){
            if(s=="D"){
                int x=st.top();
                st.push(2*x);
            }else if(s=="C"){
                st.pop();
            }else if(s=="+"){
                int x1=st.top(); st.pop();
                int x2=st.top();
                int y=x1+x2;
                
                st.push(x1);
                st.push(y);
                
            }else{
                int x=stoi(s);
                st.push(x);
            }
        }
        int sum=0;
        while(st.size()){
            sum+=st.top();
            st.pop();
        }
        
        return sum;
    }
};