class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        int curr=nums[0];
        int count=0;
        
        int itr=2;
        for(int i=2; i<n; i++){
            // cout<<i<<" "<<itr<<endl;
            
            if(nums[i] > nums[itr-2] ){
                nums[itr++]=nums[i];
            }else count++;
        }
        
        return n-count;
        
    }
};