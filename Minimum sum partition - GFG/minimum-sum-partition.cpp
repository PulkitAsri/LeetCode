// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    long long sum=0;
	    for(int i=0; i<n; i++) sum+=arr[i];
	    
	    vector<vector<bool>> dp(n+1, vector<bool>(sum+1,0));
	    
	    //initialisation of the dp table
	    for(int i=0 ;i<=n; i++){
	        for(int j=0; j<=sum; j++){
	            if(i==0) dp[i][j]=false;
	            if(j==0) dp[i][j]=true;
	        }
	    }
	    
	    //construction of the dp table
	    for(int i=1 ;i<=n; i++){
	        for(int j=1; j<=sum; j++){
                if(arr[i-1] <= j){
                    dp[i][j]= dp[i-1][j] or dp[i-1][j-arr[i-1]];
    	        }else{
    	            dp[i][j]= dp[i-1][j];
    	        }
	        }
	    }
	    
	    int m=sum;
	    for(int i=0 ;i<=sum/2; i++){
	        if(dp[n][i]) m=min(m, (int)(sum-2*i) );
	    }
	    
	    return m;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends