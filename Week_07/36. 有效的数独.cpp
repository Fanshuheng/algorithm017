class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool cols[9][9] = {false};
        bool rows[9][9] = {false};
        bool boxes[9][9] = {false};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                } 
                int box_index = (i / 3) * 3 + j / 3;
                int value = board[i][j] - '1';
                if (cols[j][value] == true || rows[i][value] == true || boxes[box_index][value] == true) 
                    return false;
                cols[j][value] = true;
                rows[i][value] = true;
                boxes[box_index][value] = true;
            }
        }
        return true;
    }
};
