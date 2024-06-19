class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 1;
        sort(points.begin(), points.end());
        int l = points[0][0], r = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            int nl = max(l,points[i][0]);
            int nr = min(r,points[i][1]);
            if(nl <= r) {
                l = nl;
                r = nr;
            }
            else if(nl > r) {
                l = points[i][0];
                r = points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};