class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        int area=0;
        vector<int> maxLeft(n,0);
        vector<int> maxRight(n,0);
        
        int mx=height[0];
        for(int i=1; i<n; i++){
            
            maxLeft[i]=mx;
            mx=max(mx, height[i]);
        }
        
        mx=height[n-1];
        for(int i=n-2; i>=0; i--){
            
            maxRight[i]=mx;
            mx=max(mx, height[i]);
        }
        
        
        for(int i=1; i<=n-2; i++){
            int areaAbove = min(maxLeft[i], maxRight[i]) - height[i];
            if(areaAbove<0) areaAbove=0;
            
            area+=areaAbove;
            // cout<<height[i]<<" "<<maxLeft[i]<<" "<<maxRight[i]<<"=>"<< areaAbove<<endl;
        }
        
        return area;
        
    }
};