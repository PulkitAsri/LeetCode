bool compareInterval(vector<int> pair1, vector<int> pair2){
    return (pair1[1] - pair1[0] >  pair2[1] - pair2[0] );
}

class Solution {
    
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        int count=1;
        
        sort(intervals.begin(),intervals.end(),compareInterval); 
        // for(auto &pair:intervals) cout<<pair[0]<<" "<<pair[1]<<endl; 
        
        for(int i=1; i<n; i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            
            bool flag=true;   
            for(int j=0; j<i; j++){
                int c=intervals[j][0];
                int d=intervals[j][1];
                
                if(c <= a && d >= b){
                    flag=false;
                    break;
                }      
            }
            if(flag) count++;
        }
        
        return count;
    }
};