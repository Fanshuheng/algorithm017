/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //94.二叉树的中序遍历
 //思路
 //深度优先遍历的两种写法：迭代与非迭代
class Solution {
public:
    // //迭代写法
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ret;
    //     if (!root) return ret;
    //     DfsHelper(root, ret);
    //     return ret;
    // }
    // void DfsHelper(TreeNode* node, vector<int>& ret) {
    //     if (node != nullptr) {
    //         DfsHelper(node->left, ret);
    //         ret.push_back(node->val);
    //         DfsHelper(node->right, ret);
    //     }
    // }

    // //迭代写法
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ret;
    //     if (!root) return ret;
    //     DfsHelper(root, ret);
    //     return ret;
    // }
    // void DfsHelper(TreeNode* node, vector<int>& ret) {
    //     if (node != nullptr) {
    //         DfsHelper(node->left, ret);
    //         ret.push_back(node->val);
    //         DfsHelper(node->right, ret);
    //     }
    // }

    // ////非递归写法1：nullptr标记法
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ret;
    //     if (!root) return ret;
    //     stack<TreeNode*> iteration_stack;
    //     iteration_stack.push(root);
    //     while (iteration_stack.size()) {
    //         TreeNode* node = iteration_stack.top();
    //         iteration_stack.pop();
    //         if (node != nullptr) {
    //             if (node->right != nullptr) iteration_stack.push(node->right);
    //             iteration_stack.push(node);
    //             iteration_stack.push(nullptr);
    //             if (node->left != nullptr) iteration_stack.push(node->left);
    //         } else {
    //             ret.push_back(iteration_stack.top()->val);
    //             iteration_stack.pop();
    //         }
    //     }
    //     return ret;
    // }

    ////非递归写法2：嵌套while法
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> iteration_stack;
        while (root != nullptr || !iteration_stack.empty()) {
            while (root != nullptr) {
                iteration_stack.push(root);
                root = root->left;
            }
            ret.push_back(iteration_stack.top()->val);
            root = iteration_stack.top()->right;
            iteration_stack.pop();
        }
        return ret;
    }
};

