class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        vector<pair<int,int>> ans;

        int n= nums.size();
        if(n==0) return res;
        int st=nums[0];
        int end=st;
        int x=st;
        
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]+1){
                end++;
            }else{
                ans.push_back({st,end});
                st=nums[i];
                end=st;
                x=st;
            }
        }
        
        ans.push_back({st,end}); 
        for(auto p:ans){
            if(p.first==p.second){
                res.push_back(to_string(p.first));
            }else{
                res.push_back(to_string(p.first) + "->"+ to_string(p.second));
            }
        }
        return res;
    }
};