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
private:
    bool solve(TreeNode* node, long long leftLimit, long long rightLimit) {
        if(node == nullptr) return true;
        if(node->val <= leftLimit || node->val >= rightLimit) return false;
        return solve(node->left, leftLimit, node->val) && solve(node->right, node->val, rightLimit);
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, 1LL * INT_MIN - 1, 1LL * INT_MAX + 1);
    }
};