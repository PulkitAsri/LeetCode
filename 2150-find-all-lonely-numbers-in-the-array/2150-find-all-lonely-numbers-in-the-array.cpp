class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int &x:nums){
            mp[x]++;
        }
        
        for(int &x:nums){
            if(mp.count(x+1)==0 && mp.count(x-1)==0 && mp[x]==1){
                //lonely
                ans.push_back(x);     
            }
        }
        return ans;
    }
};