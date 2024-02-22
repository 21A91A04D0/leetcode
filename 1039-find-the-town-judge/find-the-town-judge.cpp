class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) return 1;
        map<int, int> mp;
        for(auto it : trust) {
            mp[it[1]]++;
        }
        int mx = -1;
        for(auto it : mp) {
            if(it.second == n - 1) {
                mx = it.first;
            }
        }
        if(mx == -1) return -1;
        for(auto it : trust) {
            if(it[0] == mx) return -1;
        }
        return mx;
    }
};