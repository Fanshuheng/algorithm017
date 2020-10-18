class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> ans;
        Traceback(n, k, 0, 1, ret, ans);
        return ret;
    }
    void Traceback (int n, int k, int num, int cur, vector<vector<int>>& ret, vector<int>& ans) {
        if (num == k) {
            ret.push_back(ans);
            return;
        }
        for (int i = cur; i <= n; i++) {
            ans.push_back(i);
            Traceback(n, k, num + 1, i + 1, ret, ans);
            ans.pop_back();
        }
    }
};
