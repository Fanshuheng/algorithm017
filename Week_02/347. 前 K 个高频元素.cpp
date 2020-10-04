//题号347
//思路
//1.先用哈希表对数组进行统计，然后对哈希表进行排序，返回元素值最大的前四个元素
//2.

class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};
class Solution {
public:
    // ////排序做法
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     vector<int> ret;
    //     if (nums.empty()) return ret;
    //     unordered_map<int, int> hash_map;
    //     for (auto& e : nums) {
    //         hash_map[e]++;
    //     }
    //     vector<pair<int, int>> tmp(hash_map.begin(), hash_map.end());
    //     sort(tmp.begin(), tmp.end(), mycomparison());
    //     for (int i = 0; i <k; i++) ret.push_back(tmp[i].first);
    //     return ret;
    // }

    // ////桶排序做法
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     vector<int> *bucket = new vector<int>[nums.size() + 1];
    //     vector<int> ret;
    //     unordered_map<int, int> hash_map;
    //     for (int i = 0; i < nums.size(); i++) {
    //         hash_map[nums[i]]++;
    //     }
    //     for (auto& m : hash_map) {
    //         bucket[m.second].push_back(m.first);
    //     }
    //     for (int i = nums.size(); i >= 0 && ret.size() < k; i--) {
    //         for (auto& e : bucket[i]) ret.push_back(e);
    //     }
    //     return ret;
    // }

    ////小顶堆做法
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty()) return ret;

        //哈希统计
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]]++;
        }

        //维护小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> min_heap;
        for (auto& m : hash_map) {
            if (min_heap.size() < k || m.second > min_heap.top().second) min_heap.push(m);
            if (min_heap.size() > k) min_heap.pop();
        }

        //输出
        ret.resize(k);
        for (int i = k-1; i >= 0; i--) {
            ret[i] = min_heap.top().first;
            min_heap.pop();
        }
        return ret;
    }
};

