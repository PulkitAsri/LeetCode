class Solution {
    int countDigits(int n){
        int count=0;
        while(n>0){
            count++;
            n/=10;
        }
        return count;
    }
    
    int makeFirstSeq(int count){
        int x=1;
        int ans=1;
        while(--count){
            ans*=10;
            ans+=++x;
        }
        return ans;
    }
    
    int onesOf(int count){
        int x=1;
        int ans=1;
        while(--count){
            ans*=10;
            ans+=x;
        }
        return ans;
    }
    
    
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int lowDigits=countDigits(low);
        int highDigits=countDigits(high);
        for(int d=lowDigits; d<=highDigits; d++){
            int seq= makeFirstSeq(d);
            int ones= onesOf(d);
            for(int i=0; i< 10-d; i++){
                if(low<=seq && seq<=high){
                    ans.push_back(seq);
                }else if(seq > high){
                    break;
                }
                seq+=ones;
            }
        }
        return ans;
    }
};