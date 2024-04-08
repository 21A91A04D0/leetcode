class Solution {
public:
    bool safe(int row, int col, vector<string> &board, int n) {
        int duprow = row;
        int dupcol = col;
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        col = dupcol;
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row < n ; row++) {
            if(safe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<vector<string>> ans;
        vector<string> board(n, s);
        solve(0, board, ans, n);
        return ans;

    }
};