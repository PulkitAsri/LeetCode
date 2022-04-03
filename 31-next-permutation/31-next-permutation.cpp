class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return;
        
        int r=n-1;
        int l=n-2;

        //Thought Process=> for future Self
        // first find a decreasing sequence fromm back

        // lets Assume 1 3 5 4 2 case

        // 1  3(L)  5(R)  4   2

        // A) -> find num that is greater then nums[L] from the back
        // [2 > 3(L)]? (X) skip..... [4 > 3(L)]? (found)=> 4

        // B) -> swap Them 
        // 1  2(L)  5(R)  3   2  => still (5,3,2) is decreasing 

        // C) -> put 5 3 2 in increqsing order ...* so basically reverse [R,n-1]
        

        if(nums[l] < nums[r]){
            // no decreasing sequence
            swap(nums[r], nums[l]);
        }else{
            // wait till its a decreasing order
            while((l>= 0) && (nums[l] >= nums[r])){
                r--;
                l--;
            }
            // CORNER CASE
            if(l== -1){
                reverse(nums.begin(),nums.end());
                return;
            }
            
            //(A)
            int idx=n-1;
            while(idx>=0 && nums[idx] <= nums[l]) idx--;
            
            //(B)
            swap(nums[idx], nums[l]);
            
            //(C)
            reverse(nums.begin() + r, nums.end());
        }
        
    }
};