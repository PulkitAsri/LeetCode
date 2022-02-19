class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        set<long long> s;
        if(finalSum%2!=0){
            vector<long long> v(s.begin(), s.end());
            return v;
        }
        
        long long temp=0;
        long long evens=2;
        while(temp<finalSum){
            temp+=evens;
            s.insert(evens);
            evens+=2;
        }
        
        if(temp!=finalSum){
            if(s.count(temp-finalSum) != 0){
                s.erase(temp-finalSum);
            }else{
                vector<long long> v(s.begin(), s.end());
                return v;
            }
        }
        
        vector<long long> v(s.begin(), s.end());
        return v;
        
    }
};