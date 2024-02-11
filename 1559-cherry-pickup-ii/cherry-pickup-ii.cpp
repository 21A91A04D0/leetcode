class Solution {
public:
    int dp[71][71][71];
    int grid(int i, int j, int j1, vector<vector<int>> &mat, int m, int n){
        if(j < 0 || j1 < 0 || j == n || j1 == n) return 0;
        if(i == m) return 0;
        if(dp[i][j][j1] != -1) return dp[i][j][j1];
        int res = 0;
        vector<int> a = {-1, 0, 1};
        for(auto q : a) {
            for(auto w : a) {
                if(j == j1){
                    res = max(res,mat[i][j] + grid(i + 1, j + q, j1 + w, mat, m, n));
                }
                else{
                    res = max(res,mat[i][j] + mat[i][j1] + grid(i + 1, j + q, j1 + w, mat, m, n));
                }
            }
        }
        return dp[i][j][j1] = res;
    }
    int cherryPickup(vector<vector<int>>& gride) {
        int m = gride.size();
        int n = gride[0].size();
        memset(dp, -1, sizeof(dp));
        return grid(0, 0, n - 1, gride, m, n);
    }
};