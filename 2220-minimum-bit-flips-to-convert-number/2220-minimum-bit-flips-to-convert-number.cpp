class Solution {
public:
    int countSetBits(int n) {
        if (n == 0) return 0;
        else return (n & 1) + countSetBits(n >> 1);
    }
    int minBitFlips(int start, int goal) {
        return countSetBits(start^goal);
    }
};