class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int state=0;
        //0-> not started
        //1->increasing 
        //2-> decreasing
        
        int n=arr.size();
        int changes=0;
        
        for(int i=0; i<n-1; i++){
            int diff=arr[i+1]-arr[i];
            if(diff==0){ 
                return false;
            }else if(state==0){
                if(diff< 0) return false;
                else state=1;
            }else if((state==1 and diff< 0) or (state==2 and diff> 0)){
                changes++;
                state=(state==1)? 2: 1;
                if(changes > 1) return false;
            }
        }
        return changes==1;
    }
};