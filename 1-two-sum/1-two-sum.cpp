class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();i++){
            int toFind=target-nums[i]; 
            
            if(mp.count(toFind)!=0){
                ans[0]=mp[toFind];
                ans[1]=i;
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};