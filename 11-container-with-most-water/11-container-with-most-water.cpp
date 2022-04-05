class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        
        int l=0; 
        int r=n-1;
        
        int m=0;
        while(l<r){
            int w=r-l;
            int area= min(height[l],height[r])*w;
            
            m=max(m,area);
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            } 
        }
        
        return m;
    }
};