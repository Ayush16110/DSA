/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    bool isValidBST(TreeNode* root, long long low, long long high) {
        if (root == nullptr)
            return true;
        if (root->val >= high || root->val <= low)
            return false;
        if (!isValidBST(root->left, low, root->val))
            return false;
        if (!isValidBST(root->right, root->val, high))
            return false;
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, 1LL * INT_MIN - 1, 1LL * INT_MAX + 1);
    }
};