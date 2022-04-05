// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{  
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n= arr.size();
        vector<vector<bool>> dp(102,vector<bool> (100002,0));
        
        //initialisation
        for(int i=0; i<=n; i++){
            for (int j=0; j<=sum; j++){
                if(i==0 && j!=0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        
        for(int i=1; i<=n; i++){
            for (int j=1; j<=sum; j++){
                if(arr[i-1] <= j){
                    // either include =>{n-1, sum- arr[n-1]}
                    // or exclude => {n-1, sum}
                    dp[i][j]= dp[i-1][j - arr[i-1]] or dp[i-1][j];
                }else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        // return 0;
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends