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
    int ans = 0;
    struct Info {
        int sum;
        int maxVal;
        int minVal;
        bool isValid;
    };

    Info solve(TreeNode* node) {
        if(node == nullptr) return {0, INT_MIN, INT_MAX, true};

        Info left = solve(node->left);
        Info right = solve(node->right);
        int sum = left.sum + right.sum + node->val;

        if(left.isValid and right.isValid and left.maxVal < node->val and right.minVal > node->val) {
            ans = max(ans, sum);
            return {sum, max(node->val, right.maxVal), min(node->val, left.minVal), true};
        }

        return {sum, max(node->val, right.maxVal), min(node->val, left.minVal), false};
    }
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};