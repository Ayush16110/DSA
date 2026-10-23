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
    bool isBST(TreeNode* node, long long low, long long high) {
        if(node == nullptr) return true;
        if(node->val <= low || node->val >= high) return false;
        if(!isBST(node->left, low, node->val)) return false;
        if(!isBST(node->right, node->val, high)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, (1LL * INT_MIN) - 1,(1LL* INT_MAX) + 1);
    }
};