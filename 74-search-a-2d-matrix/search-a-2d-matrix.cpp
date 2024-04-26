class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1;
        int len = matrix[0].size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(matrix[mid][0] <= target and matrix[mid][len] >= target) {
                // if(matrix[mid][0] == target) return true;
                for(int i = 0; i <= len; i++) {
                    if(matrix[mid][i] == target) return true;
                }
                return false;
            }
            else if(matrix[mid][0] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }
};