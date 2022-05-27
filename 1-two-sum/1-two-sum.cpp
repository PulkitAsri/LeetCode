class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp; //map to <number left, index>
        
        vector<int> ans(2,-1);
        for(int i=0 ;i<n; i++){
            int x=nums[i];
            if(mp.count(target-x)!=0){
                ans[0]= mp[target-x];
                ans[1]= i;
                return ans;
            }
            mp[x]=i;
        }
        
        return ans; // -1,-1
    }
};