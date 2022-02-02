class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        // for(auto &i:intervals) cout<<i[0]<<"-"<<i[1]<<" "; cout<<endl;
        vector<int> temp(2,0);
        
        for(int i=0; i< n; i++){
            
            int st= intervals[i][0];
            int end= intervals[i][1];    
            int nextSt = (i< n-1)? intervals[i+1][0]: INT_MAX;
            int nextEnd= (i< n-1)? intervals[i+1][1]: INT_MAX;
            int mx=end;
            
            while(nextSt <= mx){    
                mx=max(mx,nextEnd);
                
                //updation
                i++;
                nextSt = (i< n-1)? intervals[i+1][0]: INT_MAX;
                nextEnd= (i< n-1)? intervals[i+1][1]: INT_MAX;      
            }
            
            temp[0]=st; temp[1]=mx;
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};