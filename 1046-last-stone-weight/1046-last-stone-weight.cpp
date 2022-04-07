class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n=stones.size();
        
        priority_queue<int> pq;
        for(int x:stones) pq.push(x);
        
        while(pq.size() > 1){
            int x1=pq.top();
            pq.pop();
            int x2=pq.top();
            pq.pop();

            int diff=abs(x1-x2);
            if(diff!=0) pq.push(diff);
            
            // cout<<x1<<" "<<x2<<" "<<diff<<endl;
            
        }  
        return (pq.size()==0)?0:pq.top();
    }
};