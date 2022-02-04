class Solution {
    int func(int n, int k, vector<int> &circle, int stIdx){
        
        if(n==1) return circle[stIdx];
        
        int removeIdx=(stIdx+ k -1)%(n);   
        circle.erase(circle.begin()+removeIdx);
    
        if(removeIdx==(n-1)) removeIdx=0;
        
        return func(n-1,k,circle,removeIdx);
    }
public:
    int findTheWinner(int n, int k) {
        vector<int> circle(n+1,0);
        for(int i=0;i<n+1;i++) circle[i]=i+1;
        return func(n,k,circle,0);
    }
};