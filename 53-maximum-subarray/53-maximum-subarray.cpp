class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        
        int mx=INT_MIN;
        for(int &x: nums) if(x<0) mx=max(mx,x);
        int curr=0;   
        for(int i=0; i<n; i++){
            curr+=nums[i];
            if(curr<0){
                //Kya Hi Fayda be
                curr=0;
            }else{
                mx=max(mx,curr);
            }
        }
        return mx;
    }
};