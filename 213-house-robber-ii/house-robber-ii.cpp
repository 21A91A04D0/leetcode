class Solution {
public:
    int fun(int ind, vector<int> &nums, vector<int> &dp) {
        if(ind < 0) return 0;
        if(ind == 0) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + fun(ind - 2, nums, dp);
        int notPick = fun(ind - 1, nums, dp);
        
        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);
        for(int i = 0 ; i < nums.size() ; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        return max(fun(temp1.size() - 1, temp1, dp1), fun(temp2.size() - 1, temp2, dp2));
    }
};