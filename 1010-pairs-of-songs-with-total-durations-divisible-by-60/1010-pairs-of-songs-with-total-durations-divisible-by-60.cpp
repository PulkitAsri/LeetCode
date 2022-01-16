class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        unordered_map<int,int> map;
        
        int n=time.size();
        for(int i=0; i<n; i++){
            count+= map[(60-(time[i]%60))%60];   
            map[time[i]%60]++;
            
            cout<<map[time[i]%60]<<" ";
        }
        cout<<endl;
        return count;
    }
};