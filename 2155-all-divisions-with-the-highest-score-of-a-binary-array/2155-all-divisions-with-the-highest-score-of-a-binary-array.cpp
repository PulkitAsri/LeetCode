class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int left0=0;
        int right1=0;
        
        for(int i=0; i<n; i++){
            if(nums[i]==1) right1++;
        }
        left0=n-right1;
        
        int maxScore=max(left0,right1);
        
        for(int i=0; i<=n; i++){
            int currScore=right1 + left0;
            if(currScore > maxScore){
                maxScore=currScore;
                ans.clear();
                ans.push_back(i);
            }else if(currScore == maxScore){
                ans.push_back(i);
            }
            //update
            if(i==n) break;
            if(nums[i]==0){
                left0++;
            }else{
                right1--;     
            }  
        }
        
        return ans;
        
    }
};