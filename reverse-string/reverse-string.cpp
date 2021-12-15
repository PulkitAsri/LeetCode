class Solution {
public:
    void reverseString(vector<char>& s) {
        recursive(s, 0, s.size() - 1);
    }
    
    void recursive(vector<char>& s, int start, int end){
        if(start > end) return;
            
        swap(s[start],s[end]);
        
        recursive(s, start+1, end-1);
    }
};