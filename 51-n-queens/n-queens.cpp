class Solution {
public:
    // bool safe(int row, int col, vector<string> &board, int n) {
    //     int duprow = row;
    //     int dupcol = col;
    //     while(row >= 0 && col >= 0) {
    //         if(board[row][col] == 'Q') return false;
    //         row--;
    //         col--;
    //     }
    //     row = duprow;
    //     col = dupcol;
    //     while(col >= 0) {
    //         if(board[row][col] == 'Q') return false;
    //         col--;
    //     }
    //     col = dupcol;
    //     while(row < n && col >= 0) {
    //         if(board[row][col] == 'Q') return false;
    //         col--;
    //         row++;
    //     }
    //     return true;
    // }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> upperDiagonal, vector<int> lowerDiagonal, vector<int> leftSide) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row < n ; row++) {
            if(upperDiagonal[n - 1 + col - row] != 1 && lowerDiagonal[row + col] != 1 && leftSide[row] != 1) {
                board[row][col] = 'Q';
                lowerDiagonal[row + col] = 1;
                leftSide[row] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, n, upperDiagonal, lowerDiagonal, leftSide);
                board[row][col] = '.';
                lowerDiagonal[row + col] = 0;
                leftSide[row] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> upperDiagonal((2 * n) - 1, 0);
        vector<int> lowerDiagonal((2 * n) - 1, 0);
        vector<int> leftSide(n, 0);
        string s(n, '.');
        vector<vector<string>> ans;
        vector<string> board(n, s);
        
        solve(0, board, ans, n, upperDiagonal, lowerDiagonal, leftSide);
        
        
        return ans;

    }
};