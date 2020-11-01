class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        //特判
        if (dict.find(endWord) == dict.end()) return vector<vector<string>>();
        
        pair<int, vector<vector<string>>> dfs_ret = {-1, vector<vector<string>>()};
        vector<string> tmp_ans;
        tmp_ans.push_back(beginWord);
        Traceback(dfs_ret, dict, tmp_ans, beginWord, endWord, 0);
        return dfs_ret.second;
    }
    void Traceback(pair<int, vector<vector<string>>>& ret, unordered_set<string>& dict, vector<string>& tmp_ans, string cur, string& endWord, int depth) {
        if (cur == endWord) {
            if (ret.first == -1 || depth < ret.first) {
                ret = {depth, vector<vector<string>> (1, tmp_ans)};
            } else if (depth == ret.first) ret.second.push_back(tmp_ans);
            return;
        }
        //剪枝：如果已经找到了一条路径，而当前回溯分支的长度比这条路径要长，那么将这个分支剪掉
        if (ret.first != -1 && ret.first <= depth) return;
        
        for (int i = 0; i < cur.size(); i++) {
            char c = cur[i];
            for (char j = 'a'; j <= 'z'; j++) {
                cur[i] = j;
                if (dict.find(cur) == dict.end()) continue;
                dict.erase(cur);
                tmp_ans.push_back(cur);
                Traceback(ret, dict, tmp_ans, cur, endWord, depth + 1);
                tmp_ans.pop_back();
                dict.insert(cur);
            }
            cur[i] = c;
        }
    }
};
