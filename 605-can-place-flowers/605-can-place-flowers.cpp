class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int potSize=flowerbed.size();
        for(int i=0; i< potSize; i++){
            
            int left = i-1>=0 ? flowerbed[i-1] : 0;
            int right= i+1< potSize ? flowerbed[i+1] : 0;
            
            if(flowerbed[i]==0 && left==0 && right==0){ 
                flowerbed[i]=1;
                count++;
            }
        }
        cout<<endl;
        
        return count>=n;
    }
};