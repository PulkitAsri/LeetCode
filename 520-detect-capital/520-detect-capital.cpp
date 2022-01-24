class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        bool isCapitalFirst=false;
        int capCount=0;
        for(int i=0; i<n; i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                capCount++;
                if(i==0) isCapitalFirst=true;
            }
        }
        
        return ((isCapitalFirst and capCount==1) or capCount==n or capCount==0);
    }
};