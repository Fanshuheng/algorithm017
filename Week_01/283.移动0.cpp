class Solution {
public:
    //双指针覆盖解法
    void moveZeroes(vector<int>& nums) {
        //1.边界条件：如果nums是空的
        if (nums.empty()) return;
        
        //2.快指针先遍历一次
        int fast = 0, slow = 0;
        for (fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        //3.慢指针将后面的覆盖掉
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
