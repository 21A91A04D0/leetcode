class Solution {
public:
    
    int fun(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        if(j < 0 ) return i + 1;
        if(i < 0 ) return j + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = fun(i - 1, j - 1, word1, word2, dp);
        return dp[i][j] = min(1 + fun(i - 1, j, word1, word2, dp), 
        min(1 + fun(i, j - 1, word1, word2, dp), 
        1 + fun(i - 1, j - 1, word1, word2, dp)));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return fun(word1.size() - 1, word2.size() - 1, word1, word2, dp);
    }
};