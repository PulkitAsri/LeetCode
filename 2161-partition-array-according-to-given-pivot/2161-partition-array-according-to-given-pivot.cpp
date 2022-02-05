class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> lessOnes;
        vector<int> greatOnes;
        int np=0;
        int ns=0;
        int ng=0;
        
        for(int i=0;i<n;i++){
            if(nums[i] < pivot){
                lessOnes.push_back(nums[i]);
                ns++;
            }else if(nums[i] > pivot){
                greatOnes.push_back(nums[i]);
                ng++;
            }else{
                np++;
            }
        }
        
        // for(int i=0;i<ns;i++) cout<< lessOnes[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<ng;i++) cout<< greatOnes[i]<<" ";
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            if(i< ns) nums[i]=lessOnes[i];
            else if(i>=ns+np) nums[i]=greatOnes[i-(ns+np)];
            else nums[i]=pivot;
        }
        return nums;
        
    }
};