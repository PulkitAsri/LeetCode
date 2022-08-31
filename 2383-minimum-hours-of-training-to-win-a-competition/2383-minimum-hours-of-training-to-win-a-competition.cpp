class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        int n= energy.size();
        int energySum = 0;
        for(int x: energy) energySum+=x;
        if(energySum >= initialEnergy){
            ans+= energySum - initialEnergy + 1;
        }
        
        for(int i: experience){
            if( i >= initialExperience){
                ans+= i - initialExperience + 1;
                initialExperience += i - initialExperience + 1;
            }
            initialExperience += i ;
        }
        
        return ans;
    }
};