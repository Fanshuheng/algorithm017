class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            if (nums[mid] > nums[(mid + 1) % nums.size()]) {
                return nums[(mid + 1) % nums.size()];
            } else if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                right = mid - 1;
            }
        }
        return nums[(right + 1) % nums.size()];;
    }
};
