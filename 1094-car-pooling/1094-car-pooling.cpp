class Solution {
    
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> tracker(1001,0);
        
        for(vector<int> &eachTrip: trips){
            tracker[eachTrip[1]]+=eachTrip[0];
            tracker[eachTrip[2]]-=eachTrip[0];
        }
        
        int passInCar=0;
        
        for(int i=0;i<1000;i++){
            passInCar+=tracker[i];
            if(passInCar > capacity) return false;
            
            cout<<tracker[i]<<" ";
        }
        return true;  
    }
};