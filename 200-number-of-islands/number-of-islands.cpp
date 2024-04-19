class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, -1, 0, 1};
        while(!q.empty()) {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int new_row = r[i] + nrow;
                int new_col = c[i] + ncol;
                if(new_row >=0 && new_row < n and new_col >= 0 and new_col < m && grid[new_row][new_col] == '1' && vis[new_row][new_col] == -1) {
                    vis[new_row][new_col] = 1;
                    q.push({new_row, new_col});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == -1 and grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
        
    }
};