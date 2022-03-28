class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        
        int l=0;
        int r=n-1;
        
        while(l <= r){
            int m = (l+r)/2;
            if(target < nums[m] ){
                r= m-1;
            }else if(target > nums[m]){
                l= m+1;
            }else{
                return m;
            }
        }
        
        return -1;
        
    }
};