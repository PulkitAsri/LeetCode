class Solution {
    
    //BRUTE FORCE
    int bruteForce(vector<int>& arr){
        //max{ MaxLength, max{ min(range in [x,y])*(Y-X)}
        int n=arr.size();
        
        int maxLength= *max_element(arr.begin(),arr.end());
        int maxArea=0;
        for(int i=0; i<n; i++){
            int minEle=arr[i];
            for(int j=i+1; j<n; j++){
                minEle=min(minEle, arr[j]);
                maxArea=max(maxArea, minEle*(j-i+1));
                // cout<<maxArea<<" "<<minEle<<" | ";
            }
            cout<<endl;
        }
        return max(maxArea,maxLength);
    }
    
    
    
    //TRYING TO OPTIMISE
    
    int optimisedSolution(vector<int>& arr){
        
        int n=(int)arr.size();
        stack<pair<int,int>> stackL;
        stack<pair<int,int>> stackR;
        
        vector<int> minIndexL(n,0);
        vector<int> minIndexR(n,0);
        
        
        // Finding Min in left
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
        
        
        // Finding Min in right
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
      
        int maxArea=0;
        for(int i=0; i<n; i++){
            // cout<<(minIndexR[i]-minIndexL[i]-1)<<" ";
            maxArea=max(maxArea, (arr[i] * (minIndexR[i]-minIndexL[i]-1))); 
        }
        // cout<<endl;
        return maxArea;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        return optimisedSolution(heights);
    }
};