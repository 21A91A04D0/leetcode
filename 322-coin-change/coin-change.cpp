class Solution {
public:
    long long dp[13][10001];
    long long coins(vector<int> &nums, int target, int ind) {
        if (ind >= nums.size()) {
            if(target == 0) return 0;
            return INT_MAX;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        // pick
        long long a = INT_MAX;
        long long b = INT_MAX;
        if(nums[ind] <= target) {
            a = 1 + coins(nums, target - nums[ind], ind);
        }
        // non - pick
        b = coins(nums, target, ind + 1);
        return dp[ind][target] = min(a, b);
    }
    int coinChange(vector<int>& coin, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = coins(coin, amount, 0);
        if(res == INT_MAX) return -1;
        return res;
    }
};