class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        int odd=n/2;
        vector<int> evenIdxs(n -odd,0);
        vector<int> oddIdxs(odd,0);
        
        for(int i=0; i<n; i++){
            if(i%2==0){
                evenIdxs[i/2]=nums[i];
            }else{
                oddIdxs[i/2]=nums[i];
            }
        }
        
        sort(evenIdxs.begin(), evenIdxs.end());
        sort(oddIdxs.begin(), oddIdxs.end());
        reverse(oddIdxs.begin(), oddIdxs.end());

        
        for(int i=0; i<n; i++){
            if(i%2==0){
                nums[i]=evenIdxs[i/2];
            }else{
                nums[i]=oddIdxs[i/2];
            }
        }
        
        
        return nums;
        
    }
};