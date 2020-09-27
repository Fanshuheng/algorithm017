//1.暴力：遍历两个不同下标i,j,时间复杂度O(n^2),空间复杂度O(1)
//2.哈希表：遍历过程中，将遇到每个数的“互补数“放进哈希表，接下来遇到了这个互补数就返回真，时间复杂度O(n),空间复杂度O(n)
//3.排序+双指针(不合题意，因为会改变数组下标):先排序，然后用双指针夹逼,时间复杂度O(nlogn),空间复杂度O(1)
class Solution {
public:
    // 一遍哈希
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        if (nums.empty()) return ans;
        map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            if (hash_map.find(target - nums[i])==hash_map.end()) 
                hash_map[nums[i]] = i;
            else {
                ans.push_back(hash_map[target - nums[i]]);
                ans.push_back(i);
                break;
            }
        } 
        return ans;
    }

    // //排序加双指针
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> ans;
    //     if (nums.empty()) return ans;
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0, j = nums.size() - 1; i < j; ) {
    //         if (target - nums[i] > nums[j]) i++;
    //         else if (target - nums[i] < nums[j]) j--;
    //         else {
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             break;
    //         }
    //     }
    //     return ans;
    // }
};
