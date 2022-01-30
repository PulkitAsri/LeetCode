class Solution {
    void reverse(vector<int>& arr, int n, int start, int end) {
        for(int i=0; i<= (end-start)>>1; i++){
            swap(arr[start+i],arr[end-i]);
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        
        int n= nums.size();
        k%= n;         
        if(k==0) return;   
        reverse(nums, n, 0, n-k-1);
        reverse(nums, n, n-k ,n-1);
        reverse(nums, n, 0, n-1);
    }
};