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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }
    bool inorder(TreeNode* root, TreeNode*& prev) {
        //cout << "Address of prev: " << &prev << "\n";
        if (!root) return true;
        bool l = inorder(root->left, prev);
        if (prev && root->val <= prev->val) {
            return false;
        }
        prev = root;
        bool r = inorder(root->right, prev);
        return l && r;
    }
};
