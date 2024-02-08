class Solution {
public:
    int dp[10001];
    int fun(int ind, int n, vector<int> &sq, int target) {
        int ans = 100000;
        if(target == 0) return 0;
        if(target < 0) return 1000000;
        if(dp[target] != -1) return dp[target];
        for(int i = ind ; i < n ; i++) {
            ans = min(ans,1 + fun(i, n, sq, target - sq[i]));
        }
        return dp[target] = ans;
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i = 1 ; i <= 100 ; i++) {
            sq.push_back(i * i);
        }
        memset(dp, -1, sizeof(dp));
        int ans = fun(0, sq.size(), sq, n);
        return ans;
    }
};