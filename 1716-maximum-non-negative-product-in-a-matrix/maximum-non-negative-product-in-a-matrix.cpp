typedef long long ll;
int sm = -1e9 + 7;
int mod = 1e9 + 7;
typedef pair<ll, ll> p;

class Solution {
public:
    pair<ll,ll> product(vector<vector<int>> &grid, int row, int col, int m, int n, vector<vector<p>> &dp) {
        if(row == m - 1 and col == n - 1) {
            return {grid[row][col],grid[row][col]};
        }
        if(dp[row][col].first != sm and dp[row][col].second != sm) return dp[row][col];
        pair<ll, ll> left = {0, 0};
        pair<ll, ll> right = {0, 0};
        bool l = false;
        bool r = false;
        if(row + 1 < m) {
            l = true;
            left = product(grid, row + 1, col, m, n, dp);
        }
        if(col + 1 < n) {
            r = true;
            right = product(grid, row, col + 1, m, n, dp);
        }
        ll val = grid[row][col];
        ll fir;
        ll sec;
        if(val < 0) {
            if(l && r) {
                sec = val * max(left.first, right.first);
                fir = val * min(left.second, right.second);
            }
            else if(l) {
                fir = val * left.second;
                sec = val * left.first;
            }
            else {
                fir = val * right.second;
                sec = val * right.first;
            }
        }
        else {
            if(l && r) {
                sec = val * min(left.second, right.second);
                fir = val * max(left.first, right.first);
            }
            else if(l) {
                sec = val * left.second;
                fir = val * left.first;
            }
            else {
                sec = val * right.second;
                fir = val * right.first;
            }
        }
        return dp[row][col] = {fir,sec};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<p>> dp(m,vector<p>(n,{sm, sm}));
        pair<ll, ll> res = product(grid, 0, 0, m, n, dp);
        
        ll ans = max(res.first, res.second);
        if(ans < 0) return -1;
        return ans%(int)mod;
    }
};