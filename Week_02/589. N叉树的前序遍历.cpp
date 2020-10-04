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
    // ////递归写法
    // vector<int> preorder(Node* root) {
    //     vector<int> ret;
    //     DfsHelper(root, ret);
    //     return ret;
    // }
    // void DfsHelper(Node* node, vector<int>& ret) {
    //     if (node != nullptr) {
    //         ret.push_back(node->val);
    //         for (int i = 0; i < node->children.size(); i++) DfsHelper(node->children[i], ret);
    //     }
    // }

    ////迭代写法（不用那种嵌套while的写法了，难理解）
    vector<int> preorder(Node* root) {
        vector<int> ret;
        stack<Node*> call;
        if (root != nullptr) call.push(root);
        while (!call.empty()) {
            root = call.top();
            call.pop();
            ret.push_back(root->val);
            for (int i = root->children.size() - 1; i >= 0; i--) {
                call.push(root->children[i]);
            }
        }
        return ret;
    }
};

