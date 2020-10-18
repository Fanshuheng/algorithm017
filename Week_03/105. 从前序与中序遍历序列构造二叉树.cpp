/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int index = 0;
        stack<TreeNode*> st;
        st.push(root);
        for (int i = 1; i < preorder.size(); i++) {
            auto cur = st.top();
            if (cur->val != inorder[index]) {
                cur->left = new TreeNode(preorder[i]);
                st.push(cur->left);
            } else {
                while (!st.empty() && st.top()->val == inorder[index]) {
                    cur = st.top();
                    st.pop();
                    index++;
                }
                cur->right = new TreeNode(preorder[i]);
                st.push(cur->right);
            }
        }
        return root;
    }
};
