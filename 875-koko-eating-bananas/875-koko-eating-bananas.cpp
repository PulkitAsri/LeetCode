#define ll long long
class Solution {
    
    bool checkBananas(vector<int> piles, ll h,ll k){
        ll count=0;
        for(int x: piles ){
            count+= (x%k ==0)? x/k: (x/k)+1;
        }
        return count<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();
        
        ll l=0;
        ll r=1e9;
        
        //Binary Search between 0, 10^9 
        // => log(10^9) => 29.89 
        // => max 30 times
        
        while(r-l > 1){
            ll m =(l+r)/2;
            
            if(checkBananas(piles,h,m))
                r=m;
            else
                l=m;       
        }
        return r;
    }
};