class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int, int> mp;
        int p=0;
        vector<int> prefix(n,0);
        
        for(int i=0; i<n; i++){
            p+=nums[i];
            prefix[i]=p;
        }
        
        //Applying 
        for(int i=0; i<n; i++){
            
            if(prefix[i]==k) ans++;
            
            //check if prefix suppose 'w'
            if(mp.count(prefix[i] - k)!=0){
                ans+=mp[prefix[i] - k];
            }
            
            mp[prefix[i]]++;
        }
        return ans;
    }
};