class Solution {
public:
    int dp[100][100];
    int fun(int r, int c, int n, vector<vector<int>> &matrix){
        cout << r << " " << c << " ";
        if((r < n) && (c < 0 or c >= n)) return INT_MAX;
        if(r >= n) return  0;
        if(dp[r][c] != 200) return dp[r][c];
        int mn = min(fun(r+1, c-1, n, matrix), fun(r+1,c,n, matrix));
        int re = min(mn,fun(r+1, c+1, n, matrix));
        
        int result = matrix[r][c] + re;
        dp[r][c] = result;
        return result;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = r;
        int n = r;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                dp[i][j] = 200;
            }
        }
        // for(int i = 0 ; i < n ; i++) {
        //     for(int j = 0 ; j < n ; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        // }
        int res = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            res = min(res, fun(0, i, n, matrix));
        }
        
        return res;
    }
};