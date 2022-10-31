class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n= arr.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);

        for(int i=0; i<n; i++){
            if(i-1>=0 && arr[i-1] < arr[i]){
                dp1[i]= max(dp1[i], dp1[i-1]+1);
            }

        }

        for(int i=n-1; i>=0; i--){
            if(i+1<n && arr[i+1] < arr[i]){
                dp2[i]= max(dp2[i], dp2[i+1]+1);
            }
        }
        
//         for(int i=0; i<n; i++) cout<<dp1[i]<<" "; cout<<endl;
//         for(int i=0; i<n; i++) cout<<dp2[i]<<" "; cout<<endl;

        int ans=0;
        for(int i=0; i<n; i++){
            if(dp1[i]!=1 and dp2[i]!=1)
                ans= max(ans, dp1[i] + dp2[i] - 1);
        }
        
        return ans;
    }
};
// [2,1,4,7,3,2,5]
// [2,2,2]
// [0,1,2,3,4,5,6,7,8,9]

// 1 1 2 3 2 2 3 
// 2 1 3 3 2 1 1 
// 1 1 1 
// 1 1 1 
// 1 2 3 4 5 6 7 8 9 10 
// 1 1 1 1 1 1 1 1 1 1 