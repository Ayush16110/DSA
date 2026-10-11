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
    int count = 0;
    bool inorder(TreeNode* node, int k) {
        if(node == nullptr) return false;

        if(inorder(node->left, k)) return true;
        count++;
        if(count == k) {
            ans = node->val;
            return true;
        }
        if(inorder(node->right, k)) return true;
        return false;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};