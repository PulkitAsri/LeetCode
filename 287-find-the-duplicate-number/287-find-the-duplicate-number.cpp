class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        // vector<bool> freq(100002,false);
        for(int i=0; i<n; i++){ 
            if(nums[0]==nums[nums[0]]) return nums[0];
            swap(nums[0],nums[nums[0]]);
        }  
        return -1;
    }
};