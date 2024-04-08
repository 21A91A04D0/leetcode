class Solution {
public:
    int dp[2501][2502];
    int LIC(vector<int> &nums, int ind, int prev_ind) {
        if(ind == nums.size()) return 0;
        int np = 0;
        int p = 0;
        // not pick;
        if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];
        np = LIC(nums, ind + 1, prev_ind);

        //pick
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            p = 1 + LIC(nums, ind + 1, ind);
        }
        return dp[ind][prev_ind + 1] = max(p, np);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return LIC(nums, 0, -1);
    }
};