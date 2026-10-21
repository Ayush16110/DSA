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
    int height(TreeNode* node) {
        int count = 0;
        while(node != nullptr) {
            count++;
            node = node->left;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftNodes = 0;
        int rightNodes = 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(leftHeight == rightHeight) {
            leftNodes = (1LL << leftHeight) - 1;
            rightNodes = countNodes(root->right);
        } else {
            leftNodes = countNodes(root->left);
            rightNodes = (1LL << rightHeight) - 1;
        }

        return leftNodes + rightNodes + 1;
    }
};