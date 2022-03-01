class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int q=nums1.size();
        int n=nums2.size();
        vector<int> allAns(n,-1);
        vector<int> ans(q,-1);
        
        stack<int> s;
        vector<int> indexOf(1e4 +1,-1);
        
        for(int i=n-1; i>=0; i--){
            indexOf[nums2[i]]=i;
            // cout<<nums2[i]<<" "<<i<<endl;
            if(s.empty()){
                allAns[i]=-1;
                s.push(nums2[i]);
                continue;
            }else if(!s.empty() && nums2[i] > s.top()){
                while(!s.empty() && nums2[i] > s.top()) s.pop();
                
                if(s.empty()) allAns[i]=-1;
                else allAns[i]=s.top();
                
            }else if(!s.empty() && nums2[i] < s.top()){
                allAns[i]=s.top();
            }
            s.push(nums2[i]);
        }
        
        // for(int i=0; i<n; i++) cout<<allAns[i]<<endl;
        for(int i=0; i<q; i++){
            ans[i]=allAns[indexOf[nums1[i]]];
        }
        return ans;
        
    }
};