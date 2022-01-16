class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> arr(n,0);
        
        int maxD=INT_MIN;
        int nearOccIndex=-1;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                arr[i]= nearOccIndex==-1 ? INT_MAX : i-nearOccIndex;
            }else{
                //save the seat
                nearOccIndex=i;
            }   
        }
        
        nearOccIndex=-1;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==0){
                arr[i]= nearOccIndex==-1 ? arr[i] : min(nearOccIndex-i,arr[i]);
            }else{
                //save the seat
                nearOccIndex=i;
            }   
        }
        
        for(int x: arr) maxD=max(maxD,x);
        
        return maxD;
    }
};