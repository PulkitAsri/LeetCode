class Solution {
public:
    long long minimumRemoval(vector<int>& b) {
    sort(b.begin(), b.end());
    
    long long remaining = 0, n = b.size();
    for (int i = 0; i < n; ++i)
        remaining = max(remaining, b[i] * (n - i));
        return accumulate(b.begin(), b.end(), 0LL) - remaining;
    }
};