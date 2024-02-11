class Solution {
public:
    int dp[71][71][71];
    int grid(int i, int j, int i1, int j1, vector<vector<int>> &mat, int m, int n){
        if(j < 0 || j1 < 0 || j == n || j1 == n) return INT_MIN;
        if(i == m and i1 == m) return 0;
        if(dp[i][j][j1] != -1) return dp[i][j][j1];
        int res = 0;
        vector<int> a = {-1, 0, 1};
        for(auto q : a) {
            for(auto w : a) {
                res = max(res, grid(i + 1, j + q, i1 + 1, j1 + w, mat, m, n));
            }
        }
        if(j == j1) {
            res += mat[i][j];
        }
        else res += mat[i][j] + mat[i1][j1];
        return dp[i][j][j1] = res;
    }
    int cherryPickup(vector<vector<int>>& gride) {
        int m = gride.size();
        int n = gride[0].size();
        memset(dp, -1, sizeof(dp));
        return grid(0, 0, 0, n - 1, gride, m, n);
    }
};