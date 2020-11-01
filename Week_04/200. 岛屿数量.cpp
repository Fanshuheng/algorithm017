class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int max_row = grid.size(), max_col = grid[0].size();
        for (int i = 0; i < max_row; i++) {
            for (int j = 0; j < max_col; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '0';
                    //BFS开始
                    queue<pair<int, int>> bfs_call;
                    bfs_call.push(make_pair(i, j));
                    while (!bfs_call.empty()) {
                        auto size = bfs_call.size();
                        while (size-- > 0) {
                            auto cur = bfs_call.front();
                            bfs_call.pop();
                            
                            //搜索相邻节点
                            auto tmp_row = cur.first, tmp_col = cur.second;
                            if (tmp_row + 1 < max_row && grid[tmp_row + 1][tmp_col] == '1') {
                                grid[tmp_row  + 1][tmp_col] = '0';
                                bfs_call.push(make_pair(tmp_row + 1, tmp_col));
                            }
                            if (tmp_col + 1 < max_col && grid[tmp_row][tmp_col + 1] == '1') {
                                grid[tmp_row][tmp_col + 1] = '0';
                                bfs_call.push(make_pair(tmp_row, tmp_col + 1));
                            }
                            if (tmp_row - 1 >= 0 && grid[tmp_row - 1][tmp_col] == '1') {
                                grid[tmp_row - 1][tmp_col] = '0';
                                bfs_call.push(make_pair(tmp_row - 1, tmp_col));
                            }
                            if (tmp_col - 1 >= 0 && grid[tmp_row][tmp_col - 1] == '1') {
                                grid[tmp_row][tmp_col - 1] = '0';
                                bfs_call.push(make_pair(tmp_row, tmp_col - 1));
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
