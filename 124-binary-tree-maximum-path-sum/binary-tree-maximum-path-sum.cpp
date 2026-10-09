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
    int ans = INT_MIN;
    int solve(TreeNode* node) {
        if(node == nullptr) return 0;
        int left = solve(node->left);
        int right = solve(node->right);

        ans = max(ans, node->val + max(0, left) + max(0, right));
        return node->val + max({0, left, right});
    }
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};