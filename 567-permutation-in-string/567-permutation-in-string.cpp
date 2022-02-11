class Solution {
    
    bool checkZeroes(vector<int> &freq){
        for(int i=0; i<26; i++) 
            if(freq[i]!=0) 
                return false; 
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        
        if(n2<n1) return false;
        
        
        vector<int> freq(26,0);
        
        for(int i=0; i<n1; i++) freq[s1[i]-'a']++;
        
        //first window
        for(int i=0; i<n1; i++) freq[s2[i]-'a']--;
        
        if(checkZeroes(freq)) return true;
        
        for(int i=1; i<= n2-n1; i++){
            freq[s2[i-1]-'a']++;
            freq[s2[n1+i -1]-'a']--;
            // cout<<"exiting->"<<s2[i-1]<<" ";
            // cout<<"entering->"<<s2[n1+i-1]<<endl;
            
            if(checkZeroes(freq)) return true;
        }
        
        return false;
                
    }
};