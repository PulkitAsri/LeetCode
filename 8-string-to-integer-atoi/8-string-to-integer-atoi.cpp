#define ll long long int
class Solution {
public:
    int myAtoi(string s) {
        ll ans=0;
        bool started=false;
        bool isPositive=true;
        
        for(char &c:s){
            if(c==' ' && !started) 
                continue;

            else if( !started && ( c=='+' or c=='-')){
                if(!started) isPositive=(c=='-')? false: true;
                started=true;
            }
            else if(c>='0' && c<='9'){
                started=true;
                int x=c-'0';
                ll temp=ans*10 + x;
                
                if(isPositive and temp>=INT_MAX) 
                    return ans=INT_MAX;
                else if(!isPositive and -1*temp<=INT_MIN) 
                    return ans=INT_MIN; 
                ans=temp;
            }
            else 
                break;
        
        }
        return isPositive? (int)ans: (int)-1*ans;
    }
};