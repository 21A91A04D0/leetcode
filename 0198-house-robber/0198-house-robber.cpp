class Solution {
public:
    int dp[100];
    int fun(int i, vector<int> &num, int n) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = num[i] + max(fun(i + 2, num, n), fun(i + 3, num, n));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        for(int i = 0 ; i < 100 ; i++) {
            dp[i] = -1;
        }
        int ans = fun(0, nums, nums.size());
        int ans1 = fun(1, nums, nums.size());
        return max(ans, ans1);
    }
};