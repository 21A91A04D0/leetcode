class Solution {
public:
    int dp[51][51][51];
    const int mod = 1e9 + 7;
    int helper(int r , int c, int m, int n, int moves) {
        // int sm = 0;
        if((r < 0 || c < 0 || r >= m || c >= n)) return 1;
        if(moves == 0) return 0;
        if(dp[r][c][moves] != -1) return dp[r][c][moves];
        int a = helper(r , c - 1, m, n, moves - 1) % mod;
        int b = helper(r - 1, c, m, n, moves - 1) % mod;
        int cs = helper(r + 1, c, m, n, moves - 1) % mod;
        int d = helper(r, c + 1, m, n, moves - 1) % mod;
        
        return dp[r][c][moves] = (((a + b) % mod) + ((cs + d % mod) % mod)) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(startRow, startColumn, m, n, maxMove);
        
    }
};