class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long count=0;
        int maxCost= max(cost1,cost2);
        int minCost= min(cost1,cost2);
        
        int maxOf= (total/maxCost);
        
        for(int i=0; i<=maxOf; i++){
            count+= ((total-(i*maxCost))/minCost) +1;
        }
        
        return count;
    }
};