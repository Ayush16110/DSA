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
    TreeNode* solve(TreeNode* node, TreeNode* low, TreeNode* high) {
        if(node == nullptr) nullptr;
        if(node->val >= low->val && node->val <= high->val) return node;
        if(node->val < low->val && node->right != nullptr) return solve(node->right, low, high);
        if(node->val > high->val && node->left != nullptr) return solve(node->left, low, high);
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q->val) return solve(root, p, q);
        return solve(root, q, p);
    }
};