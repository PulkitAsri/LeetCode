class Solution {
    
    int findPath(vector<vector<int>>& grid, int &n, int &m, int x, int y,int count){
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int ans=0;
            
        for(int i=0;i<4;i++){
            int a=x+dx[i];
            int b=y+dy[i];
            
            if(a>=0 && a<n && b>=0 && b<m){
                
                int temp=grid[a][b];
                if(temp==0){
                    grid[a][b]=-1;
                    ans+=findPath(grid,n,m,a,b,count+1);
                    
                }else if(temp==1){
                    grid[a][b]=-1;
                    
                }else if(temp==2){
                    if(count==(m*n)-1){
                        ans++;
                    }  
                }
                grid[a][b]=temp;  
            }  
        }
        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=0;
        int count=0;
        int startX=0,startY=0;
        
        //find starting square
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1){
                    count++;
                }else if(grid[i][j]==1){
                    startX=i;
                    startY=j;
                }
            }
        }
        grid[startX][startY]=-1;
        ans=findPath(grid,n,m,startX,startY,count+1);

        return ans;
    }
};