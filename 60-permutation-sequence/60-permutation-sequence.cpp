class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        for(int i=1; i<=n; i++) numbers.push_back(i);
    
        int fact=1;
        for(int i=1; i<n; i++) fact*=i;
        
        string ans="";
        k--; //0 based indexing
        while(true){
            ans+= to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if(numbers.size()==0){
                break;
            }else{
                k%=fact;
                fact/=numbers.size(); 
            }
            
            
        }
        return ans;
    }
};