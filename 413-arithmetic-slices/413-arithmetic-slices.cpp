class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        if(n<=2) return 0;
        
        int diff= nums[1]-nums[0];
        int prevSum= diff;
        
        int noOfAp=0;
        int counter=0;
        int ans=0;
        
        for(int i=1; i<n; i++){
            diff=nums[i]-nums[i-1];
            
            if(diff==prevSum){
                counter++;
            }else{
                if(counter>=2){
                    cout<<counter<<endl;
                    
                    int x=counter-1;
                    
                    ans+= x*(x+1)/2;  
                    counter=1;
             
                }
            }
            
            prevSum=diff;
        }
        if(counter>=2){
            cout<<counter<<endl;

            int x=counter-1;
            ans+= (x*(x+1)/2);  
            counter=1;

        }
        
        return ans;
    }
};