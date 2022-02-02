class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        vector<bool> freq(100002,false);
        for(int &x:nums){ 
            if(freq[x]) return x;
            freq[x]=true;
        }  
        return -1;
    }
};