class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustee(n+1,0);
        vector<int> trusted(n+1,0);
        for(vector<int> pair: trust){
            trustee[pair[0]]++;
            trusted[pair[1]]++;
        }
        
        for(int i=1;i<=n;i++){
            cout<<trustee[i]<<" "<<trusted[i]<<endl;
        }
        cout<<endl;
        
        for(int i=1;i<=n;i++)
            if(trustee[i]==0 && trusted[i]==n-1) 
                return i;
        
        return -1;
    }
};