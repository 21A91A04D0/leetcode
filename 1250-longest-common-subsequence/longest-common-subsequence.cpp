class Solution {
public:
    int fun(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        if(i >= text1.size() || j >= text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        int res = 0;
        if(text1[i] == text2[j]) ans = 1 + fun(text1, text2, i+1, j+1, dp);
        res = max(fun(text1, text2, i + 1, j, dp) , fun(text1, text2, i, j + 1, dp));
        res = max(res,ans);
        dp[i][j] = res;
        return res;
    }
    int longestCommonSubsequence(string text1, string text2) {
        if(text1 == text2) return text1.size();
        vector<vector<int>> dp(1001, vector<int>(1001,-1));
        return fun(text1, text2, 0, 0,dp);
    }
};