class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int n=arr.size();
        vector<int> prefix(n,0);
        
        //Idea : make 0 <==>-1 and find the longest subarray that has sum=0
        
        prefix[0]=(arr[0]==0)?-1:1;
        for(int i=1; i<n; i++){
            int x=(arr[i]==0)?-1:1;
            prefix[i]=prefix[i-1]+x;
            
        }
        // for(int i=0; i<n; i++) cout<<prefix[i]<<endl;
        
        //prefixs should be equal for which to make the whol subarray zero
        map<int,int> minIdx;
        int ans=0;
        minIdx[0]=-1; //coz that when the sum becomes =0 ...the whole ans= whole array till there
        for(int i=0; i<n; i++){
            if(minIdx.count(prefix[i])){
                ans=max(ans, i- minIdx[prefix[i]]);
            }else{
                minIdx[prefix[i]]=i;
            }
        }
        return ans;
        
    }
};