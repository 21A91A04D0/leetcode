class Solution {
public:
    int res = 0;
    vector<int> ans;
    void fun(vector<int> &nums, int ind, int prev , vector<int> &ds, int n, vector<int>&dp) {
        if(ind >= n) {
            if(ds.size() > ans.size()) {
                ans=ds;
            }
            return;
        }
        if(dp[ind] < (int)ds.size() and nums[ind] % prev == 0) {
            dp[ind]=ds.size();
            ds.push_back(nums[ind]);
            fun(nums, ind + 1, nums[ind], ds, n,dp);
            ds.pop_back();
        }
        // non - pick
        fun(nums, ind + 1, prev, ds, n,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ind = 0;
        vector<int> ds;
        vector<int>dp(nums.size()+1,-1);
        if(nums[0] == 1) ind = 1;
        fun(nums, ind, 1, ds, nums.size(),dp);
        if(nums[0] == 1) ans.push_back(1);
        return ans;
        
    }
};