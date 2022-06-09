class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2,-1);
        int n= numbers.size();
        
        int l=0; int r=n-1;
        
        while(l<r){
            int sum=numbers[l]+numbers[r];
            if(sum==target){
                ans[0]=l+1;
                ans[1]=r+1;
                break;
            }else{
                //update
                if(sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};