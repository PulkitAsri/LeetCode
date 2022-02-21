class Solution {
    
    int freqTable(vector<int>& nums) {
        int n=nums.size();
        map<int,int> freq;
        for(int &x: nums){
            freq[x]++;
            if(freq[x]== ceil(n/2.0)) return x;
        }
        return 0;
    }
    
    int mooreVoting(vector<int>& nums){
        int n=nums.size();
        int count=0;
        int currCandidate=-1;
        for(int &x: nums){
            if(count==0){
                currCandidate=x;
                count++; 
            }
            else if(currCandidate==x) count++;
            else count--;
        }
        return currCandidate;
    }
    
public:
    int majorityElement(vector<int>& nums) {
        // return freqTable(nums);
        return mooreVoting(nums);
    }
};