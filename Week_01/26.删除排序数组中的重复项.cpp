//思路：
//这道题目要求用原地算法修改数组，删除重复元素
//1.快慢指针：当nums[i-1]==nums[i]时，慢指针留在原地，快指针向前走；当nums[i-1]！=nums[i](i是快指针)时，快指针所指元素覆盖慢指针，然后快指针和慢指针一起向前走一格；当快指针遍历完成后，慢指针的值就是不重复元素的个数(跳出循环的时候slow多加了1)
//2.哈希表法（不符题意）：遍历一次，把元素都放到哈希表去，最后用新的数组按顺序存放哈希表的键值即可

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 1) return nums.size();
        int slow = 1;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast-1] != nums[fast]) {
                nums[slow++] = nums[fast]; 
            }
        }
        // nums.resize(slow);
        return slow;
    }
};
