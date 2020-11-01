class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0; 
        for (int i = 1, last = 0; i < nums.size(); i++) {
            while (last + nums[last] < i && last < i) last++;
            dp[i] = dp[last] + 1;
        }
        return dp[nums.size() - 1];
    }
};
