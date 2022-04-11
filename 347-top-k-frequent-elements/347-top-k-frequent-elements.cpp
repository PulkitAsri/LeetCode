class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        vector<int> ans;
        int n=nums.size();

        for(int x:nums){
            mp[x]++;
        }
        
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};