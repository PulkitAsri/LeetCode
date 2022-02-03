class Solution {
    
    // bool binSearch(vector<int> &arr,int n,int x){
    //     int l=0;
    //     int r=n-1;
    //     while(r>=l){
    //         int mid=(r+l)/2;
    //         if(x==arr[mid]){
    //             return true;
    //         }else if(x >arr[mid]){
    //             l=mid+1;
    //         }else if(x < arr[mid]){
    //             r=mid-1;
    //         }
    //     }
    //     return false;
    // }
    
    
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int n= nums1.size();
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;        
        int count=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp2[nums3[i]+nums4[j]]++;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x=-1*(nums1[i]+nums2[j]);
                count+=mp2[x];
            }
        }
        
        return count;
    }
};