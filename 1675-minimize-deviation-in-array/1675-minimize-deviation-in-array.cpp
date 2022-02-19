class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> pq;
        int minEle=INT_MAX;
        
        
        
        
        for(int &x:nums){ 
            if(x%2==1) x*=2;
            pq.push(x);
            //max = pq.top
            minEle= min(minEle,x); //for the difference   
        }
        
        int diff= pq.top()-minEle;
        
        
        while(pq.top()%2==0){
            int max=pq.top();
            pq.pop();
            max/=2;
            pq.push(max);
            
            minEle=min(minEle, max);
            diff=min(diff, pq.top() -minEle);
        }
        
        return diff;
        
    }
};