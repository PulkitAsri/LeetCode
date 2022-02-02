class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        int count=0;
        stack<pair<char, int>> st;
        vector<int> idxs;
        
        for(int i=0; i<n; i++){
            char c=s[i];
            if(c>='a' && c<='z') continue; 
            if(c=='('){
                st.push(make_pair(c, i));
            }else if(c==')'){
                if(st.empty()){
                    count++;
                    idxs.push_back(i);        
                }else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            count++;
            idxs.push_back(st.top().second);
            st.pop();
        }
        sort(idxs.begin(),idxs.end());
        
        // for(int i=0;i<count;i++) cout<<idxs[i]<<" "; cout<<endl;
        
        string ans="";
        int itr=0;
        int i=0;
        while(i<n){
            if(itr>=count || i!=idxs[itr]){
                ans+=s[i++];
            }else{  
                itr++;
                i++;
            }
        }
        return ans;  
    }
};