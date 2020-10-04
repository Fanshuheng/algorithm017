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
class Solution {
public:
    // ////递归写法
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ret;
    //     DfsHelper(root, ret);
    //     return ret;
    // }
    // void DfsHelper(TreeNode* node, vector<int>& ret) {
    //     if (node != nullptr) {
    //         ret.push_back(node->val);
    //         DfsHelper(node->left, ret);
    //         DfsHelper(node->right, ret);
    //     }
    // }

    // ////迭代写法（nullptr标记）
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ret;
    //     stack<TreeNode*> call;
    //     if (root != nullptr) call.push(root);
    //     while (!call.empty()) {
    //         auto node = call.top();
    //         call.pop();
    //         if (node != nullptr) {
    //             if (node->right) call.push(node->right);
    //             if (node->left) call.push(node->left);
    //             call.push(node);
    //             call.push(nullptr);
    //         } else {
    //             ret.push_back(call.top()->val);
    //             call.pop();
    //         }
    //     }
    //     return ret;
    // }

    ////迭代写法（嵌套while）
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> call;
        while (!call.empty() || root != nullptr) {
            while (root != nullptr) {
                ret.push_back(root->val);
                call.push(root);
                root = root->left;
            }
            root = call.top();
            call.pop();
            root = root->right;
        }
        return ret;
    }
};

