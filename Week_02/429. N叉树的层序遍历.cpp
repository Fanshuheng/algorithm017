/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // ////递归写法:虽然递归无法直接实现层次遍历，但递归前序遍历的顺序总是从左往右的，那么只要我们给递归的函数中传入层数参数，即可实现层次遍历
    // vector<vector<int>> levelOrder(Node* root) {
    //     vector<vector<int>> ret;
    //     DfsHelper(root, ret, 0);
    //     return ret;
    // }
    // void DfsHelper(Node* node, vector<vector<int>>& ret, int level) {
    //     if (node != nullptr) {
    //         if (ret.size() <= level) {
    //             ret.push_back(vector<int>());
    //         }
    //         ret[level].push_back(node->val);
    //         for (auto& n : node->children) {
    //             DfsHelper(n, ret, level + 1);
    //         }
    //     }
    // }

    ////递归写法:虽然递归无法直接实现层次遍历，但递归前序遍历的顺序总是从左往右的，那么只要我们给递归的函数中传入层数参数，即可实现层次遍历
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        queue<Node*> call;
        if (root != nullptr) call.push(root);
        while (!call.empty()) {
            vector<int> single_level_ret;
            int num = call.size();
            while (num-- > 0) {
                auto node = call.front();
                call.pop();
                single_level_ret.push_back(node->val);
                for (auto& n : node->children) {
                    if (n != nullptr) call.push(n);
                }
            }
            ret.push_back(single_level_ret);
        }
        return ret;
    }
};

