class Solution {
public:
    int dp[501];
    int partition(vector<int> &nums, int n, int ind, int k,int prev) {
        int res = INT_MIN;
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int mx = INT_MIN;
        for(int i = ind ; i < ind + k ; i++) {
            if(i < n){
                mx = max(nums[i],mx);
                res = max(res, (mx * (i - prev)) + partition(nums, n, i + 1, k, i));
            } 
        }
        return dp[ind] = res;
    }
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        memset(dp, -1, sizeof(dp));
        int ans = partition(A, A.size(), 0, k,-1);
        return ans;
    }
};