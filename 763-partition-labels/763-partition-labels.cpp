class Solution {
    
    vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> &intervals){
        int n=intervals.size();
        
        vector<pair<int,int>> ans;
        // for(auto &i:intervals) cout<<i[0]<<"-"<<i[1]<<" "; cout<<endl;
        pair<int,int> temp(2,0);
        
        for(int i=0; i< n; i++){
            
            int st= intervals[i].first;
            int end= intervals[i].second;   
            
            if(st==-1) continue;
            int nextSt = (i< n-1)? intervals[i+1].first: INT_MAX;
            int nextEnd= (i< n-1)? intervals[i+1].second: INT_MAX;
            int mx=end;
            
            while(nextSt <= mx){    
                mx=max(mx,nextEnd);
                
                //updation
                i++;
                nextSt = (i< n-1)? intervals[i+1].first: INT_MAX;
                nextEnd= (i< n-1)? intervals[i+1].second: INT_MAX;      
            }
            
            temp.first=st; temp.second=mx;
            ans.push_back(temp);
        }
        
        return ans;
        
    }
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        
        vector<int> ans;
        vector<pair<int,int>> intervals(26, {-1,-1});
        
        for(int i=0; i<n; i++){
            char c= s[i];
            if(intervals[c-'a'].first == -1){
                intervals[c-'a'].first=i;
                intervals[c-'a'].second=i;
            }else{
                intervals[c-'a'].second=i;
            }
        }
        
        
        // now sort and merge intevals
        
        sort(intervals.begin(), intervals.end());
        intervals= mergeIntervals(intervals);
        
        
        for(auto i:intervals){
            // cout<<i.first<<" "<<i.second<<endl;;
            ans.push_back(i.second - i.first + 1 );
        }
        return ans;
        
        
    }
};