class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int ans=INT_MAX;
        int p=0;
        for(int i=0; i<n; i++){
            prefix[i]= nums[i] + p; 
            p = prefix[i];
            if(prefix[i] == x){
                ans=min(ans, i+1);
            }
        }
        int s=0;
        for(int i=n-1; i>=0; i--){
            suffix[i]= nums[i] + s; 
            s = suffix[i];
            if(suffix[i]== x){
                ans=min(ans, n-i);
            }
        }
        
        // for(int x: prefix) cout<<x<<" "; cout<<endl;
        // for(int x: suffix) cout<<x<<" "; cout<<endl;
        
        for(int i=n-1; i>0; i--){
            if(x < suffix[i]) break;
            
            int numberNeeded= x - suffix[i];
            //search the number betwen 0<----> (i-1)
            // but 0 has no need coz it wont have any numbers to search from and also (prefix.begin() -1) doesnt work
            
            
            auto itr = lower_bound(prefix.begin(), prefix.begin()+ i-1  , numberNeeded);
            // cout<< *(prefix.begin() + -1) <<endl;
            // cout<< suffix[i]<<" "<< numberNeeded<<" "<< *itr<<"=> "<<endl;
            
            int idx=  (int)(itr - prefix.begin());
            
            if(*itr == numberNeeded ){
                ans= min(ans, n-i + idx+1 );
                // cout<<(n-i)<<" "<<idx<<endl;
            }
        }
        
        return (ans==INT_MAX)? -1: ans;
        
    }
};