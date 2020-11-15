class Solution {
    bitset<9> rows[9] = {0};
    bitset<9> cols[9] = {0};
    bitset<9> boxes[9] = {0};
    bool stop = false;
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    auto value = board[i][j] - '1';
                    auto boxes_index = (i / 3) * 3 + j / 3;
                    rows[i] |= (1 << value);
                    cols[j] |= (1 << value);
                    boxes[boxes_index] |= (1 << value);
                }
            }
        }
        Traceback(board, 0, 0);
    }
    void Traceback(vector<vector<char>>& board, int row, int col) {
        if (col == board.size()) {
            row += 1;
            col = 0;
            if (row == board.size()) {
                stop = true;
                return;
            }
        }
        if (board[row][col] == '.') {
            for (char k = '1'; k <= '9'; k++) {
                auto value = k - '1';
                auto boxes_index = (row / 3) * 3 + col / 3;
                if (rows[row][value] == true || cols[col][value] == true || boxes[boxes_index][value] == true) continue;
                else {
                    rows[row] |= (1 << value);
                    cols[col] |= (1 << value);
                    boxes[boxes_index] |= (1 << value);

                    board[row][col] = k;
                    Traceback(board, row, col + 1);
                    
                    if (stop) break;
                    board[row][col] = '.';

                    rows[row] &= ~(1 << value);
                    cols[col] &= ~(1 << value);
                    boxes[boxes_index] &= ~(1 << value);
                }
            }
        } else {
            Traceback(board, row, col + 1);
        }
    }
};
