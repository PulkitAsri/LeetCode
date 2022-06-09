class Solution {
    struct compare {
        inline bool operator()(const std::string& first,
                const std::string& second) const
        {
            return first.size() > second.size();
        }
    };
public:
    int maxProduct(vector<string>& words) {
        // sort(words.begin(), words.end());
        int n=words.size();
        vector<vector<int>> mp(n,vector<int>(26,0)); //index-> 
        
        for(int i=0; i<n; i++){
            string word= words[i];
            for(char &c: word) mp[i][c-'a']++;
        }
        
        long long ans=0;
        for(int i=0 ;i<n; i++){
            for(int j=i+1; j<n; j++){
                //26 checks if they have any same chars
                bool flag=true;
                // cout<<words[i]<<" "<<words[j]<<endl;
                for(int k=0; k<26; k++){
                    // cout<<mp[i][k]<<","<< mp[j][k]<<" ";
                    if((mp[i][k]!=0 && mp[j][k]!=0)){
                        flag=false;
                        break;
                    }
                }
                // cout<<endl;
                if(flag){
                    long long mul= words[i].length() * words[j].length();
                    // if(mul>ans) cout<<words[i]<<" "<<words[j]<<endl;
                    ans=max(ans, mul);
                }
                
            }
        }
        
        
        return ans;
    }
};