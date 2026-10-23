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
    int k = 0;
    int ans = 0;
    bool inorder(TreeNode* node) {
        if(node == nullptr) return false;
        if(inorder(node->left)) return true;
        count++;
        if(count == k) {
            ans = node->val;
            return true;
        }
        if(inorder(node->right)) return true;
        return false;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root);
        return ans;
    }
};