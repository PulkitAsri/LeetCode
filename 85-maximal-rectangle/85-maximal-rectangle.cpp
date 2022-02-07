class Solution {
    
    //Helper Fn
    vector<int> nearest_smallest_to_Left(vector<int>& arr, int n){
        
        stack<pair<int,int>> stackL;   
        vector<int> minIndexL(n,0);
        
        for(int i=0; i<n; i++){    
            int height=arr[i];
            
            if(stackL.empty()){
                minIndexL[i]=-1;
                
            }else if(!stackL.empty() && height > stackL.top().first){
                minIndexL[i]=stackL.top().second;
                
            }
            else if(!stackL.empty() && height <= stackL.top().first){
                
                while(!stackL.empty() && height <= stackL.top().first){
                    stackL.pop();
                }
                
                if(stackL.size()==0)
                    minIndexL[i]=-1;
                else 
                    minIndexL[i]=stackL.top().second;
            }
            
            pair<int,int> prL(height,i);
            stackL.push(prL);  
        }
        return minIndexL;   
    }
    
    //Helper Fn
    vector<int> nearest_smallest_to_right(vector<int>& arr, int n){
        stack<pair<int,int>> stackR;
        
        vector<int> minIndexR(n,0);
        for(int i=n-1; i>=0; i--){
            int height=arr[i];
            
            if(stackR.empty()){
                minIndexR[i]=n;
                
            }else if(!stackR.empty() && height > stackR.top().first){
                minIndexR[i]=stackR.top().second;
                
            }
            else if(!stackR.empty() && height <= stackR.top().first){
                while(stackR.size()>0 && height <= stackR.top().first){
                    stackR.pop();
                }
                
                if(stackR.empty())
                    minIndexR[i]=n;
                else 
                    minIndexR[i]=stackR.top().second;
            }   
            
            pair<int,int> prR(height,i);
            stackR.push(prR);  
        }
        return minIndexR; 
    }
    
    //Logic Fn
    int max_area_histogram(vector<int>& arr){
        
        int n=(int)arr.size();
        stack<pair<int,int>> stackR;
        
        vector<int> minIndexL(n,0);
        vector<int> minIndexR(n,0);  
        // Finding Min in left and right....of a particular bar
        minIndexL= nearest_smallest_to_Left(arr,n);
        minIndexR= nearest_smallest_to_right(arr,n);
        
        int maxArea=0;
        for(int i=0; i<n; i++)
            maxArea=max(maxArea, (arr[i] * (minIndexR[i]-minIndexL[i]-1))); 
        
        return maxArea;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) { 
        int r=matrix.size();
        int c=matrix[0].size();
        
        vector<int> hist(c,0);
        for(int i=0; i<c; i++) hist[i]= matrix[0][i] -'0';
        int maxArea= max_area_histogram(hist);
        
        // uncomment for DRY RUN
        // for(int i=0; i<c; i++) cout<<hist[i]<<" "; cout<<endl;

        for(int i=1; i<r; i++){
            //merge the above ans into the historgam 
            for(int j=0; j<c; j++){
                if(matrix[i][j]=='0') hist[j]=0;
                else hist[j]+=(matrix[i][j] -'0');
            }
            //uncomment for DRY RUN
            // for(int i=0; i<c; i++) cout<<hist[i]<<" "; cout<<endl;
            maxArea=max(maxArea, max_area_histogram(hist));
        }
        return maxArea;  
    }
};