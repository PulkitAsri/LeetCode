class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();   
        
        vector<int> freq(3,0);
        for(int &x:nums) freq[x]++;
        
        int curr=0,itr=0;   
        while(curr<=2 && itr < n){
            if(freq[curr]--==0) curr++; 
            else nums[itr++]=curr;        
        } 
    }
};