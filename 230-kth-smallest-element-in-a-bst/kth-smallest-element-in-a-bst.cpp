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
    int count = 0;
    int ans = 0;
    bool solve(TreeNode* node, int k) {
        if(node == nullptr) return false;
        if(solve(node->left, k)) return true;
        count++;
        if(count == k) {
            ans = node->val;
            return true;
        }
        if(solve(node->right, k)) return true;
        return false;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;
        solve(root, k);
        return ans;
    }
};