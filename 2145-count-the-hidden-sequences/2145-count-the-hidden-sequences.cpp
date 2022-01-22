#define ll long long int
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        vector<ll> arr(n+1,0);
        
        //making a sample array for min and max
        int mn=0,mx=0;
        for(int i=1; i<n+1; i++){
            arr[i]=arr[i-1]+ differences[i-1];
            mn=mn<arr[i]?mn:arr[i];
            mx=mx>arr[i]?mx:arr[i];
        }
        
        int ans=(upper-lower)-(mx-mn) +1;
        return ans>=0? ans: 0;
    }
};