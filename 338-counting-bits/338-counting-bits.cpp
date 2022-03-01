class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0; i<=n; i++){
            int x=0;
            for(int j=i; j>0; j=j>>1){
                x += (j&1);
            }
            ans.push_back(x);
        }
        return ans;
    }
};