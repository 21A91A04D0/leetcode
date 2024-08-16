class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        sort(arrays.begin(), arrays.end());
        int mn = arrays[0][0];
        int ans = INT_MIN;

        int mx = arrays[0][arrays[0].size() - 1];
        int ans1 = INT_MIN;
        
        // int mx = arrays[0][arrays[0].size() - 1];
        for(int i = 1 ; i < arrays.size() ; i++) {
            auto it = arrays[i];

            ans = max(ans, it[it.size() - 1] - mn);

            ans1 = max(ans1,abs(mx - it[0]));
            mn = min(mn, it[0]);
            mx = max(mx, it[it.size() - 1]);
        }
        return max(ans,ans1);
    }
};