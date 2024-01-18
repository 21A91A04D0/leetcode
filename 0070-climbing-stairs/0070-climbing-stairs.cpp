class Solution {
public:
    int helper(int n, vector<int> &v) {
        int sm = 0;
        if(n == 0) return 1;
        if(n == -1) return 0;
        if(v[n]) return v[n];
        sm += helper(n - 1, v) + helper(n - 2, v);
        v[n] = sm;
        return sm;
    }
    int climbStairs(int n) {
        vector<int> v(46,0);
        return helper(n, v);
    }
};