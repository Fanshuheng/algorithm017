# 哈希表
+ 哈希表可用于处理以下问题：
	1. 分类：如果需要对某些元素进行分类，则可以通过某种**映射关系**，将这些**元素转换成键值**，然后利用一个`map<KeyType key, vector<ElementTYpe>>`的**哈希表**，将这些元素放到对应的`vector`就行。
		+ 题目：[49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)
		+ 注意点: 元素与键值之间的映射关系要找清楚，题49是用**排序**作为映射；
		
	2. 特定关系元素对的查找：如果希望判断是否存在与某个元素A有对应关系的另一个元素B时，可以用哈希表以B为键值、A为元素（即{B, A}）记录这个键值对；对于后续来的每个元素C，只要在表里找一找有没有以C为键值的键值对即可判断是否存在对应关系的元素；这样可以在一次遍历中完成特定关系元素对的查找。
		+ 题目：[1.两数之和](https://leetcode-cn.com/problems/two-sum/)
	
	3. 统计：哈希表可以统计一组数据中，每种元素出现的次数。
		+ 题目：[242. 有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/), [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)
	
	4. 去重 （本周课程中没提及这个用法，先不展开）

# 堆
+ 堆是一种能**在常数时间内获取最大/最小值的抽象数据结构**，其实现有多种，二叉堆只是其中一种实现，二叉堆的特点是简单容易实现。
+ 堆可用于处理以下问题：
	１. 维护k个最大最小值 
		+ 题目：[剑指 Offer 40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/),[239	滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum),[347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements)
		+ 代码：
~~~c++
class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> min_heap;
for (auto& m : hash_map) {
    if (min_heap.size() < k || m.second > min_heap.top().second) min_heap.push(m);
    if (min_heap.size() > k) min_heap.pop();
}
~~~

# 二、K叉树深度遍历、层次遍历
+ 二、K叉树深度遍历有三种：
	+ 先序遍历
	+ 中序遍历
	+ 后续遍历
+ 这三种遍历都有两种写法：**递归写法**与**迭代写法**
	+ 在递归写法中，前中后序遍历的框架是一致的，只是调用递归函数的顺序不一样而已。代码：
~~~c++
    //前序递归写法
    void DfsHelper(TreeNode* node, vector<int>& ret) {
        if (node != nullptr) {
        	ret.push_back(node->val);
            DfsHelper(node->left, ret);
            DfsHelper(node->right, ret);
        }
    }
    //中序递归写法
    void DfsHelper(TreeNode* node, vector<int>& ret) {
        if (node != nullptr) {
            DfsHelper(node->left, ret);
            ret.push_back(node->val);
            DfsHelper(node->right, ret);
        }
    }
    //后序递归写法
    void DfsHelper(TreeNode* node, vector<int>& ret) {
        if (node != nullptr) {
            DfsHelper(node->left, ret);
            DfsHelper(node->right, ret);
            ret.push_back(node->val);
        }
    }
~~~
+ 而迭代写法可分为两种：
		1. 借助nullptr标记的迭代写法
		2. 双重while的迭代写法
+ 一篇总结得很好的文章:[一文搞定二叉树遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/bang-ni-dui-er-cha-shu-bu-zai-mi-mang-che-di-chi-2/)
