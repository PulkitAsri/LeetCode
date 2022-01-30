class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> set;
        for(int x: nums){
            set.insert(x);
        }
        
        while(set.count(original)!=0){
            original=original<<1;
        }
        return original;
    }
};