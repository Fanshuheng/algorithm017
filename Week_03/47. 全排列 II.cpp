class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> is_used(nums.size(), false);
        vector<int> ans;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        Traceback(is_used, ans, nums, ret);
        return ret;
    }
    void Traceback (vector<bool>& is_used, vector<int>& ans, vector<int>& nums, vector<vector<int>>& ret) {
        if (ans.size() == nums.size()) {
            ret.push_back(ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (is_used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !is_used[i - 1]) continue;
            is_used[i] = true;
            ans.push_back(nums[i]);
            Traceback(is_used, ans, nums, ret);
            ans.pop_back();
            is_used[i] = false;
        }
    }
};
