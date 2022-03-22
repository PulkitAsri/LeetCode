class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans="";
        
        for(int i=n; i>0; i--){
            
            // cout<< i<<" "<<k<<endl;
            if(k >= (26 + i-1)){
                ans+='z';
                k-=26;
            }else if(k < (26 + i-1) && k > i){
                ans+=(char)(k - (i) +'a');
                k -= k - (i-1) ;
            }else{
                ans+='a';
                k--;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};