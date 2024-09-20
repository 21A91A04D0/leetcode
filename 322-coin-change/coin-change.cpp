class Solution {
public:

    long long helper(int target,int ind,  vector<int> &coins, vector<vector<long long>> &dp) {
        if(target == 0) {
            return 0;
        }
        if(ind >= coins.size() || target < 0) {
            return INT_MAX;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        long long pick = 1 + helper(target - coins[ind], ind, coins, dp);
        long long notpick = helper(target , ind + 1 , coins, dp);
        return dp[ind][target] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<long long>> dp(coins.size(), vector<long long>(amount + 1, -1));

        long long ans = helper(amount, 0, coins, dp);
        if(ans >= INT_MAX) return -1;
        else return (int)ans;
    }
};