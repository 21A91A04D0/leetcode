class Solution {
public:
    int dp[101][101];
    int fun(int row, int col, int m, int n) {
        if(row == m and col == n) return 1;
        if(row > m or col > n) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = fun(row + 1, col, m, n) + fun(row, col + 1, m, n);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return fun(1, 1, m, n);
    }
};