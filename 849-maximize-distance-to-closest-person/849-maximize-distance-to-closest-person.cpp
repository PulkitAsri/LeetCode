class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        
        int maxD=1;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                int left=INT_MAX;
                int right=INT_MAX;
                for(int j=i-1;j>=0;j--){
                    if(seats[j]==1){
                        left=i-j;
                        break;
                    }
                }
                
                for(int j=i+1;j<n;j++){
                    if(seats[j]==1){
                        right=j-i;
                        break;
                    }
                }
                
                int minDistance=min(left,right);
                
                maxD=max(maxD,minDistance);
            }else{
                continue;
            }  
        }
        
        return maxD;
    }
};