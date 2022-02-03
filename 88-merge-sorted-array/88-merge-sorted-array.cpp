class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int itr1=0;
        int itr2=0;
        // while(itr1<m && itr2<n){
        //     if(nums1[itr1] > nums2[itr2]){
        //         itr1++;
        //     }else{
        //         swap(nums1[itr1], nums2[itr2]);
        //         itr2++;
        //     }
        // }
        itr1=m;
        itr2=0;
        while(itr1<(m+n) && itr2< n ){
            nums1[itr1++]=nums2[itr2++];
        }
        sort(nums1.begin(),nums1.end());
        
        
    }
};


// 1 2 3 4

    
    