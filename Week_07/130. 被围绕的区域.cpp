class UnionFind {
public:
    vector<int> parent;
    int cols_num = 0, rows_num = 0;
    int dummy = 0;
    UnionFind(vector<vector<char>>& board) {
        rows_num = board.size();
        cols_num = board[0].size();
        dummy = cols_num * rows_num;
        for (int i = 0; i <= cols_num * rows_num; i++) {
            parent.push_back(i);
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    void unite(int x, int y) {
        int root_x = find(x), root_y = find(y);
        if (root_x != root_y) {
            if (root_x == dummy) {
                parent[root_y] = root_x;
            } else parent[root_x] = root_y;
        }
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        UnionFind uf(board);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    auto cur = i * uf.cols_num + j;
                    if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1) {
                        uf.unite(cur, uf.dummy);
                    } else {
                        if (i > 0 && board[i - 1][j] == 'O') uf.unite(cur,(i - 1) * uf.cols_num + j);
                        if (j > 0 && board[i][j - 1] == 'O') uf.unite(cur,i * uf.cols_num + j - 1);
                        if (i + 1 < uf.rows_num && board[i + 1][j] == 'O') uf.unite(cur,(i + 1) * uf.cols_num + j);
                        if (j + 1 < uf.cols_num && board[i][j + 1] == 'O') uf.unite(cur,i * uf.cols_num + j + 1);
                    }
                }
            }
        }
        for (int i = 0; i < uf.rows_num; i++) {
            for (int j = 0; j < uf.cols_num; j++) {
                if (board[i][j] == 'O' && (uf.find(i * uf.cols_num + j) == uf.dummy)) board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
