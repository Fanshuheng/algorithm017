class Solution {
public:
    //其实这种写法是不是一种dfs?
    bool canJump(vector<int>& nums) {
        int most_remote_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i <= most_remote_index) {
                most_remote_index = max(most_remote_index, i + nums[i]);
            }
            if (most_remote_index >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
