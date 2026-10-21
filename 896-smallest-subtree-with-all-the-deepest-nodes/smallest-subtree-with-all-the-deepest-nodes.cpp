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
    pair<TreeNode*, int> solve(TreeNode* node) {
        if(node == nullptr) return {nullptr, 0};
        auto [leftNode, leftDepth] = solve(node->left);
        auto [rightNode, rightDepth] = solve(node->right);
        TreeNode* ans = node;
        if(leftDepth > rightDepth) {
            ans = leftNode;
        } else if(leftDepth < rightDepth) {
            ans = rightNode;
        }
        return {ans, 1 + max(leftDepth, rightDepth)} ;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto [ans, depth] = solve(root);
        return ans;
    }
};