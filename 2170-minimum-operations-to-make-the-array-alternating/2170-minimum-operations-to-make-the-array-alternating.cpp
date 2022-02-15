class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> map_E(1e5 +1 ,0);
        vector<int> map_O(1e5 +1 ,0);
        
        int maxE=0;
        int prevE=0;
        int e=0;
        int pe=0;
        
        int maxO=0;
        int prevO=0;
        int o=0;
        int po=0;
        
        int m=0;
        for(int i=0; i< n; i++){
            if(i%2==0){
                map_E[nums[i]]++;
                // cout<<nums[i]<<"->"<<map_E[nums[i]]<<endl;
            }else{
                map_O[nums[i]]++;
                // cout<<nums[i]<<"->"<<map_O[nums[i]]<<endl;
            }
            m=max(m,nums[i]);
        }
        
        
        
        for (auto i = 0; i <= m; i++){

            if(map_E[i] > maxE){
                prevE = maxE;
                pe = e;

                maxE = map_E[i];
                e = i;

            }else if(map_E[i] > prevE  ){
                pe = i;
                prevE = map_E[i];
            }
            // cout<<pe<<"=>"<<prevE<<" "<<e<<"=>"<<maxE<<endl;
        }
        
        
        for (auto i = 0; i <= m; i++){
            if(map_O[i] > maxO){
                prevO = maxO;
                po = o;

                maxO = map_O[i];
                o = i;

            }else if(map_O[i] > prevO ){
                prevO = map_O[i];
                po = i;
            }
            // cout<<po<<"=>"<<prevO<<" "<<o<<"=>"<<maxO<<endl;

        }
        
        //final dry run check *debugging
        
        
        if(e!=o)
            return n - maxE -maxO;
        else{
            return min((n - maxE - prevO), (n - prevE - maxO));
        }
        return -9090;
    }
};