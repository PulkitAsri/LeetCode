class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> odds;
        vector<int> evens;
        int n=nums.size();
        
        for(int &x:nums){
            if(x<0) odds.push_back(x);
            else evens.push_back(x);
        }
        int o=0,e=0;
        for(int i=0;i<n;i++){
            if(i%2==0) nums[i]=evens[e++];
            else nums[i]=odds[o++];
        }
        return nums;
    }
};