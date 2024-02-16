class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));
        int cnt = 0;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                if(grid[i][j] == 1) cnt++;
            }
        }
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        int mx = 0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            cout << t << " ";
            mx = max(mx, t);
            q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 2;
                    cnt--;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }
        if(cnt == 0) return mx;
        return -1;
    }
};