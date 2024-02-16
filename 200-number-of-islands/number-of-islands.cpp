class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        q.push({row, col});
        while(!q.empty()) {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            // (-1, 0)  (0, 1)  (1, 0)  (0, -1)
            vector<pair<int, int>> v = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            for(auto it : v) {
                int rowf = nrow + it.first;
                int colf = ncol + it.second;
                if(rowf >= 0 and rowf < m and colf >= 0 and colf < n and vis[rowf][colf] == 0 and grid[rowf][colf] == '1') {
                    vis[rowf][colf] = 1;
                    q.push({rowf, colf});
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int cnt = 0;
        for(int row = 0 ; row < m ; row++) {
            for(int col = 0 ; col < n ; col++) {
                if(!vis[row][col] and grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};