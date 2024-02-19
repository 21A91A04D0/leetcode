class Solution {
public:
    bool isPowerOfTwo(int n) {
        // n = abs(n);
        if(n != 0 and n != INT_MIN and (n & n - 1) == 0) return true;
        return false;
    }
};