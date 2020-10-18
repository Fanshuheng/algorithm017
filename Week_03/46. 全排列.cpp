class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty()) return ret;
        vector<int> ans;
        Traceback(0, ans, nums, ret);
        return ret;
    }
    void Traceback (int level, vector<int>& ans, vector<int>& nums, vector<vector<int>>& ret) {
        if (level == nums.size()) {
            ret.push_back(ans);
            return;
        }
        
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            if (find(ans.begin(), ans.end(), *iter) == ans.end()) {
                ans.push_back(*iter);
                Traceback(level + 1, ans, nums, ret);
                ans.pop_back();
            }

        }
    }
};
