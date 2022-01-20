#define ll long long
class Solution {
    
    bool checkBananas(vector<int> &piles, int h,int k){
        int count=0;
        for(int x: piles ){
            count+= (x%k ==0)? x/k: (x/k)+1;
        }
        return count<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();
        
        int mx= piles[0];
        for(int x:piles) mx=max(mx,x);
        
        int l=0;
        int r=mx+1;
        
        //Binary Search between 0, 10^9 
        // => log(10^9) => 29.89 
        // => max 30 times
        
        while(r-l > 1){
            int m =(l+r)/2;
            
            if(checkBananas(piles,h,m))
                r=m;
            else
                l=m;       
        }
        return r;
    }
};