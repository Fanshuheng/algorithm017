class TrieNode {
public:
    string word = "";
    TrieNode* next[26] = {nullptr};
};
class Solution {
private:
    int rows = 0, cols = 0;
    vector<string> ret;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if (rows == 0 || cols == 0) return ret;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            auto cur = root;
            for (auto& w : words[i]) {
                
                auto idx = w - 'a';
                if (cur->next[idx] == nullptr) cur->next[idx] = new TrieNode;
                cur = cur->next[idx];
            }
            cur->word = words[i];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, root, i, j);
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y) {
        char c = board[x][y];
        if (c == '.' || root->next[c - 'a'] == nullptr) return;
        root = root->next[c - 'a'];
        if (root->word != "") {
            ret.push_back(root->word);
            root->word = "";
        }

        board[x][y] = '.';
        if (x - 1 >= 0) dfs(board, root, x - 1, y);
        if (y - 1 >= 0) dfs(board, root, x, y - 1);
        if (x + 1 < rows) dfs(board, root, x + 1, y);
        if (y + 1 < cols) dfs(board, root, x, y + 1);
        board[x][y] = c;
    }
};
