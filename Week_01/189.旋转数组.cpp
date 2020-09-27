//思路1：连续交换法：第i个元素换掉第i+k个元素，第i+k个元素换掉第i+2k个元素，如此类推，时间复杂度O(n)
//思路2：暴力：就真的按题目的意思那样，向右旋转n步,时间复杂度O(n*k)，k为步数
//思路3:另建数组(不符题意):另外创建一个数组，按题意放置元素,时间复杂度O(N)(一次遍历，一次拷贝)，空间复杂度O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;

        for (int start = 0; count < nums.size(); start++) {
            int cur = start;
            int pre = nums[cur];
            do {
                int next = (cur + k) % nums.size();
                int temp = nums[next];
                nums[next] = pre;
                cur = next;
                pre = temp;
                count++;
            } while (cur != start);
        }

    }
};
