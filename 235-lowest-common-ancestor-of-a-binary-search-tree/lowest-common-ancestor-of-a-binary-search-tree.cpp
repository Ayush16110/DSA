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
private:
    TreeNode* solve(TreeNode* node, TreeNode* small, TreeNode* large) {
        if(node == nullptr) return nullptr;
        if(node->val >= small->val and node->val <= large->val) return node;
        if(node->val < small->val) return solve(node->right, small, large);
        else if(node->val > large->val) return solve(node->left, small, large);
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) return solve(root, q, p);
        return solve(root, p, q);
    }
};