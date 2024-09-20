class Solution {
public:

    int robbery(int ind , vector<int> &nums , vector<int> &dp) {
        if(ind < 0 ) return 0;
        if(ind == 0) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + robbery(ind - 2, nums, dp);
        int non_pick = robbery(ind - 1, nums, dp);
        return dp[ind] = max(pick, non_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robbery(n - 1, nums, dp);
    }
};