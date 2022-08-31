class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        map<char,int> lastPosition;
        map<char,int> freq; 
        vector<char> allTypes{ 'P', 'G', 'M' };

        for(int i=0; i<n; i++){
            for(char c: garbage[i]){
                lastPosition[c]=i;
                freq[c]++;
            }
        }
        
        //Prefix Sum of Travel
        int prefix=0;
        for(int i=0; i<n-1; i++){
            travel[i]+= prefix;
            prefix= travel[i];
        }
        
        //debugging
//         cout<<"lastPlaces"<<endl; 
//         for(char c: allTypes) cout<<c<<"->"<<lastPosition[c]<<endl;
//         for(int x:travel) cout<<x<<" "; cout<<endl;
              
        int ans=0;
        for(char c: allTypes){
            int travelTime = (lastPosition[c] ==0)? 0: travel[lastPosition[c]-1];
            int pickingTime = freq[c];
            ans+= travelTime + pickingTime;
        }

        return ans;
    }
};