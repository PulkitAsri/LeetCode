class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> freq;
        for(int x: nums){
            freq[x]++;
            if(freq[x]== ceil(n/2.0)) return x;
        }
        return 0;
    }
};