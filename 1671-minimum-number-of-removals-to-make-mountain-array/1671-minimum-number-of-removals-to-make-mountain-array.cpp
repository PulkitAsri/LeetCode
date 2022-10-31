class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j] < arr[i]){
                    dp1[i]= max(dp1[i], dp1[j]+1);
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(arr[j] < arr[i]){
                    dp2[i]= max(dp2[i], dp2[j]+1);
                }
            }
        }

        // for(int i=0; i<n; i++) cout<<dp1[i]<<" "; cout<<endl;
        // for(int i=0; i<n; i++) cout<<dp2[i]<<" "; cout<<endl;

        int ans=1;
        for(int i=0; i<n; i++){
            if(dp1[i]!=1 && dp2[i]!=1)
            ans= max(ans, dp1[i] + dp2[i] -1);
        }

        return n-ans; 
    }
};