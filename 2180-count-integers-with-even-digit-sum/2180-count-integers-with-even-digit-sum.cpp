class Solution {
    int sumOfDigits(int num){
        int ans=0;
        while(num>0){
            ans+=num%10;
            num/=10;
        }
        return ans;
    }
public:
    int countEven(int num) {
        int count=0;
        while(num){
            if(sumOfDigits(num)%2==0) count++;
            num--;
        }
        return count;
    }
};