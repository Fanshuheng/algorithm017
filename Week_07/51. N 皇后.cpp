class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> board(n,string(n, '.'));
        Traceback(ret, board, n, 0);
        return ret;
    }
    void Traceback(vector<vector<string>>& ret, vector<string>& cur_board, int n, int row) {
        if (row >= n) {
            ret.push_back(cur_board);
            return;
        }
        for (int col = 0; col < cur_board[0].size(); col++) {
            if (is_vaild(cur_board, row, col)) {
                cur_board[row][col] = 'Q';
                Traceback(ret, cur_board, n, row + 1);
                cur_board[row][col] = '.';
            }
        }
    }
    bool is_vaild(vector<string>& cur_board, int row, int col) {
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (cur_board[i][j] == 'Q') 
                return false;
        }
        for (int i = row, j = col; i >= 0 && j < cur_board.size(); i--, j++) {
            if (cur_board[i][j] == 'Q') 
                return false;
        }
        for (int i = 0; i <= row; i++) {
            if (cur_board[i][col] == 'Q') 
                return false;
        }
        return true;
    }
};
