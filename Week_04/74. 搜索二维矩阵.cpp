class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row_left = 0, row_right = matrix.size() - 1, col_left = 0, col_right = matrix[0].size() - 1;
        while (row_left <= row_right) {
            auto mid = row_left + (row_right - row_left) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) {
                row_right = mid - 1; 
            } else if (matrix[mid][0] < target) {
                row_left = mid + 1;
            }
        }
        row_left = row_left - 1;
        if (row_left < 0) return false;
        while (col_left <= col_right) {
            auto mid = col_left + (col_right - col_left) / 2;
            if (matrix[row_left][mid] == target) return true;
            else if (matrix[row_left][mid] > target) {
                col_right = mid - 1; 
            } else if (matrix[row_left][mid] < target) {
                col_left = mid + 1;
            }
        }
        return false;
    }
};
