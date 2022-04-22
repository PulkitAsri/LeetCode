class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int m=INT_MAX;
        int ans=-1;
        
        for(int x:nums){
            if(m > abs(x)){
                m=abs(x);
                ans=x;
            }else if(m==abs(x)){
                if(ans<0) ans=x;
            }
        }
        
        return ans;
        
        
    }
};