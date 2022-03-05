bool comp(vector<int> &i1, vector<int> &i2){
    if(i1[0] == i2[0]) return i1[2] < i2[2];
    return i1[0] < i2[0] ;
}
class Solution {
    int allDigits(int x, vector<int>& mapping){
        int temp=1;
        int ans=0;
        if(x==0) ans= mapping[0];
        while(x){
            int t=x%10;
            
            ans+=(temp*mapping[t]);
            temp*=10;

            x/=10;
        }
        return ans;
    }   
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n= nums.size();
        
        vector<vector<int>> ds(n);
        for(int i=0; i<n; i++){
            // cout<<allDigits(nums[i], mapping)<<" ";
            ds[i]={ allDigits(nums[i], mapping), nums[i], i };      
        }
        sort(ds.begin(), ds.end(),comp);
        
        for(int i=0; i<n; i++){
            nums[i]=ds[i][1];      
        }
        return nums;
    }
};