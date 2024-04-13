class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int, pair<int, int>> mp;
        int k = 0;
        for(int i = 0 ; i < matrix.size() ; i++) {
            for(int j = 0 ; j < matrix[0].size() ; j++) {
                if(matrix[i][j] == 0) {
                    mp[k] = {i, j};
                    k++;
                }
            }
        }
        for(auto it : mp) {
            int row = it.second.first;
            int col = it.second.second;
            for(int i = 0 ; i < n ; i++) {
                matrix[row][i] = 0;
            }
            for(int j = 0 ; j < m ; j++) {
                matrix[j][col] = 0;
            }
        }

    }
};