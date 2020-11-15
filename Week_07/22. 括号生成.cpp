class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        Recursion(ret, "", 2 * n, n, n);
        return ret;
    }
    void Recursion(vector<string>& ret, string tmp_ans, int n, int left_num, int right_num) {
        if (tmp_ans.size() == n) {
            ret.push_back(tmp_ans);
            return;
        }
        if (left_num > 0) Recursion(ret, tmp_ans + "(", n, left_num - 1, right_num);
        if (right_num > 0 && right_num > left_num) Recursion(ret, tmp_ans + ")", n, left_num, right_num - 1);
    }
};
