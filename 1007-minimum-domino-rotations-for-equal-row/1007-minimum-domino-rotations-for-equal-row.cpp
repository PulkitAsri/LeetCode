class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> bestAns(7,INT_MAX);
        
        int n=tops.size();
        
        for(int b=0; b<=1; b++){
            for(int i=1 ;i<=6; i++){
                int count=0;
                bool isSame=true;
                for(int j=0; j<n; j++){
                    if(b == 0){
                        if(tops[j]!= i){
                            // swap(tops[j],bottoms[j]);
                            count++;
                            isSame= isSame && (bottoms[j]==i);
                        }
                    }else{
                        if(bottoms[j]!= i){
                            // swap(tops[j],bottoms[j]);
                            count++;
                            isSame= isSame && (tops[j]==i);
                        }
                    }
                }
                //check
                if(isSame){
                    // cout << count << endl;
                    bestAns[i]=min(bestAns[i], count);
                }
            }
        }
        
        
        int ans=-1;
        int minElement=INT_MAX;
        for(int i=1; i<=6;i++){
            if(bestAns[i] < minElement){
                minElement= bestAns[i];
                ans=i;
            }
        }
        return (ans==-1)? -1 :minElement;
        
    }
};