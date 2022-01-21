class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        int sum=0;
        int tank=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            int gain=gas[i]-cost[i];
            sum+=gain;
            tank+=gain;
            
            if(tank<0){
                tank=0;
                ans=i+1; 
            }
            
            // int tankFuture=gain + gas[(i+1)%n] -cost[((i+1)%n)];               
            cout<<gain<<" "; 
        }
        cout<<endl;
        if(sum >=0){
            //do something
            return ans;
        }else{
            return -1;
        }
        cout<<endl;
    }
};