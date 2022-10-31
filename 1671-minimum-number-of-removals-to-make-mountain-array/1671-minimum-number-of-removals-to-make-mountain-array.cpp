class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n= arr.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        vector<int> seq;
        for(int i=0; i<n; i++){
            int idx= lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
            dp1[i]= idx+1;
            if(idx==seq.size()){
                seq.push_back(arr[i]);   
            }else{
                seq[idx]= arr[i];
            }
        }
        reverse(arr.begin(),arr.end());
        
        vector<int> seq2;
        for(int i=0; i<n; i++){
            int idx= lower_bound(seq2.begin(), seq2.end(), arr[i]) - seq2.begin();
            dp2[i]= idx+1;
            if(idx==seq2.size()){
                seq2.push_back(arr[i]);   
            }else{
                seq2[idx]= arr[i];
            }
        }
        
        reverse(dp2.begin(), dp2.end());
//         for(int i=0; i<n; i++) cout<<dp1[i]<<" "; cout<<endl;
//         for(int i=0; i<n; i++) cout<<dp2[i]<<" "; cout<<endl;

        int ans=0;
        for(int i=0; i<n; i++){
            if(dp1[i]!=1 and dp2[i]!=1)
                ans= max(ans, dp1[i] + dp2[i] - 1);
        }
        
        return n- ans; 
    }
};