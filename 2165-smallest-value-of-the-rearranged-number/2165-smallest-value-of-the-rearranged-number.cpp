class Solution {
    vector<int> allDigits(long long x){
        vector<int> ans;
        x=abs(x);
        while(x>0){
            ans.push_back(x%10);
            x/=10;
        }
        return ans;
    }
    
public:
    long long smallestNumber(long long num) {
        bool isPositive=false;
        if(num>=0) isPositive=true;
        
        
        long long ans=0;
        vector<int> digits=allDigits(num);
        sort(digits.begin(), digits.end());
        
        if(isPositive){
            int zeroes=0;
            bool flag=true;
            for(int i=0; i<digits.size(); i++){
                if(digits[i]==0) zeroes++;
                else if(digits[i]!=0){
                    ans*=10;
                    ans+=digits[i];
                    
                    if(flag) while(zeroes--){ ans*=10; ans+=0;}
                    flag=false;
                }
            }
            
        }else{
            reverse(digits.begin(), digits.end());
            
            for(int i=0; i<digits.size(); i++){
                ans*=10;
                ans+=digits[i];
            }
            ans*=-1;
            
        }

        return ans;
        
    }
};