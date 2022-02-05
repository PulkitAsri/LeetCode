class Solution {
public:
    int minimumSum(int num) {
        
        vector<int> digits(4,0);
        int x=num,i=0;
        for(int i=0; i<4; i++){
            digits[i]=x%10;
            x/=10;
        }
        
        sort(digits.begin(),digits.end());
        return digits[0]*10 + digits[3]  + digits[1]*10 + digits[2];
        
    }
};