class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
        int n=heights.size();
        
        priority_queue<int, vector<int>, greater<int>> allLadders; //also a min heap of top l<number of ladders> elements
        
        for(int i=n-1; i>0; i--){
            //diffArray
            heights[i]=heights[i]-heights[i-1];
        }
        for(int i=1; i<n; i++){
            if(heights[i]<=0) continue;
            
            if( l > 0 ){
                allLadders.push(heights[i]);
                l--;
                continue;
                
            }else{
                //all ladders are used ...
                // take the smallest ladder used 
                // and if that is less than the diff
                //-><switch>
                
                if(allLadders.size() > 0 && allLadders.top() < heights[i]){
                    int x= allLadders.top();     
                    allLadders.pop();
                    allLadders.push(heights[i]);
                    
                    // use x amount of bricks ...if dont have enough-> break
                    if(b - x < 0){
                        return i-1;
                    }else{
                        b-=x;
                    }
                }else{
                    if(b - heights[i] < 0){
                        return i-1;
                    }else{
                        b-=heights[i];
                    }
                }
            }
        }
        
        return n-1; // if escaped the for loop return last index
    }
};