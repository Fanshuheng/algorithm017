/* 题号242
    思路：
    对题目的剖析：字母异位词可以这样定义：b有a中出现的所有字母，且出现的次数一样，且a、b长度相同
    （1）排序后比较即可,但要注意一下两个字符串长度不同的情况，因为当a是b的子集时equal也返回true，但a和b就不是字母异位词了；两次排序的时间复杂度O（NlogN），空间复杂度O（1）
    （2）哈希表法（统计元素出现次数）：统计a和b中每个元素出现的次数，如果元素种类和出现次数相同就是字母异位词。时间复杂度：遍历字符串+遍历哈希表O（n），空间复杂度：O（n）

*/
class Solution {
public:
    // ////排序法
    // bool isAnagram(string s, string t) {
    //     if (s.size() != t.size()) return false;
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     return equal(s.begin(), s.end(),t.begin());
    // }

    ////哈希法
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> hash_map;//字母、出现次数
        for (int i = 0; i < s.size(); i++) {
            hash_map[s[i]]++;
            hash_map[t[i]]--;
        }
        for (auto& e : hash_map) {
            if (e.second != 0) return false;
        }
        return true;
    }
};
