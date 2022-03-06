class Solution {
public:
    vector<string> cellsInRange(string s) {
        
        vector<string> ans;
        string start= s.substr(0,2);
        string end= s.substr(3,2);
        // cout<<start<<" "<<end<<endl;
        for(int i= start[0]-'A' ; i<= end[0]-'A'; i++){
            for(int j= start[1]-'0' ; j<= end[1]-'0'; j++){
                string s="  ";
                // cout<<i<<" "<<j<<endl;
                s[0]=(char)(i+'A');
                s[1]=(char)(j+'0');
                ans.push_back(s);
            }
        }
        
        return ans;
        
    }
};