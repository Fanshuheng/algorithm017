//49.字母异位词分组
//思路：排序后哈希法（映射法，通过某种方式将元素映射到一些集合中）；遍历strs,对每个元素排序，然后以排序后的字符串为键值，建立<string, vector>的哈希表，在遍历过程中将每个元素扔到对应的集合就好
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if (strs.empty()) return ret;
        //建立<string, vector>哈希表
        map<string, vector<string>> hash_map;
        //遍历strs
        for (auto& str : strs) {
            //对字符串排序
            auto tmp_str = str;
            sort(tmp_str.begin(), tmp_str.end());
            //以排序后的字符串为键值，进行归类
            // if(hash_map.find(str) == hash_map.end()) {
            //     hash_map[str] = vector<string>{str};
            // } else 
            hash_map[tmp_str].push_back(str);
        }
        //将结果放到ret里
        for (auto& m : hash_map) {
            ret.emplace_back(m.second);
        }
        return ret;
    }
};

