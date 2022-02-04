class Solution {
    
    bool binSearch(vector<int> &arr, int n, int x, int l, int r){
        while(r>=l){
            int mid=(r+l)/2;
            // cout<<"here "<<arr[mid]<<" "<<x<<endl;
            if(x==arr[mid]){
                return true;
            }else if(x > arr[mid]){
                l=mid+1;
            }else if(x < arr[mid]){
                r=mid-1;
            }
        }
        return false;
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        set<vector<int>> sett;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    //now binary search
                    
                    int x=target-((long long)nums[i]+ nums[j]+ nums[k]) ;
                    int l=k+1; int r=n-1;
                    bool inArray=binSearch(nums,n,x,l,r);
                    
                    // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" and "<<target<<endl;
                    // cout<<l<<" "<<r<<endl;
                    // cout<<inArray<<endl;
                    
                    if(inArray){
                        vector<int> temp{nums[i], nums[j], nums[k], x};
                        sort(temp.begin(),temp.end());
                        if(sett.count(temp)==0 ){
                            ans.push_back(temp);
                            sett.insert(temp);
                        }
                    }   
                }   
            }
        }
        return ans;
    }
};