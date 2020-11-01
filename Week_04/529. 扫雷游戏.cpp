class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        auto row =  click[0], col = click[1];
        auto max_row = board.size() - 1, max_col = board[0].size() - 1;        
        //1.处理情况1
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }
        //2.处理情况2，3
        queue<pair<int, int>> bfs_call;
        bfs_call.push(make_pair(row, col));
        while (!bfs_call.empty()) {
            auto size = bfs_call.size();
            while (size-- > 0) {
                auto cur = bfs_call.front();
                bfs_call.pop();

                //处理情况3：对周边节点计数，统计周围的炸弹数量
                auto near_boom_size = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        auto tmp_row = cur.first + i;
                        auto tmp_col = cur.second + j; 
                        if ((i == 0 && j == 0) || tmp_row < 0 || tmp_row > max_row || tmp_col < 0 || tmp_col > max_col) continue;
                        if (board[tmp_row][tmp_col] == 'M') near_boom_size++;
                    }
                }
                if (near_boom_size > 0) {
                    board[cur.first][cur.second] = '0' + near_boom_size;
                    continue;
                }

                //处理情况2：打开所有没有炸弹相邻节点的节点
                board[cur.first][cur.second] = 'B';
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        auto tmp_row = cur.first + i;
                        auto tmp_col = cur.second + j; 
                        if ((i == 0 && j == 0) || tmp_row < 0 || tmp_row > max_row || tmp_col < 0 || tmp_col > max_col) continue;
                        if (board[tmp_row][tmp_col] == 'E') {
                            board[tmp_row][tmp_col] = 'B';
                            bfs_call.push(make_pair(tmp_row, tmp_col));
                        }
                    }
                }
            }
        }
        return board;
    }
};
