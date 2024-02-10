class Solution {
public: 
    int ans = 0;

    int fun(int i, int j, string s, vector<vector<int>> &vis){
        if(s[i] != s[j]) return 0;
        if(j <= i) return 1;

        vis[i][j] = fun(i + 1, j - 1, s, vis);
        if(vis[i][j] == 1) ans++;
        return vis[i][j];
    }
    int countSubstrings(string s) {
        vector<vector<int>> vis(1001,vector<int>(1001,0));
        for(int i = 0 ; i < s.size() ; i++) {
            for(int j = i + 1 ; j < s.size() ; j++) {
                if(vis[i][j] == 0) {
                    fun(i,j,s,vis);
                }
            }
        }
        return ans + s.size();
    }
};