class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xoxo=0;
        for(int i:nums) xoxo= xoxo xor i;
        return xoxo;
        
    }
};