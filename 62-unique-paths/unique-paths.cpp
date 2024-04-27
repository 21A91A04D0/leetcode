class Solution {
public:
    int uniquePaths(int m, int n) {
        //combinatorics
        //ncr
        int N = m - 1 + n - 1;
        int r = m - 1; // (m - 1 or n - 1)

        long long res = 1;
        for(int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};