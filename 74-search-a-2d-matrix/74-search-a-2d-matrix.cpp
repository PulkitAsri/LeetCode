class Solution {
    int binarySearchCol(vector<vector<int>>& matrix, int n, int target){
        
        
        int l=-1;
        int r=n;
        
        while(r-l >1){
            int mid=(l+r)/2;
            if(matrix[mid][0] < target){
                l=mid;
            }else if(matrix[mid][0] > target){
                r=mid;
            }else{
                return mid;
            }
            // cout<<l<<" "<<r<<"    "<<matrix[mid][0]<<endl;
        }
        
        return (l<n && l>=0)?l:-1;
    }
    
    bool binarySearchIn(vector<vector<int>>& matrix, int row, int n, int target){
        int l=0;
        int r=n-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[row][mid] < target){
                l=mid+1;
            }else if(matrix[row][mid] > target){
                r=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
    
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = binarySearchCol(matrix, m, target);
        cout<<row<<endl;
        return (row>=0)? binarySearchIn(matrix, row, n ,target): false;

    }
};