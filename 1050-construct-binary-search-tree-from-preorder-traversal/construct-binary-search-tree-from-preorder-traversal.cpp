/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void insertElement(TreeNode* node, int val) {
        if (node == nullptr)
            return;
        if (node->val > val) {
            if (node->left == nullptr) {
                node->left = new TreeNode(val);
                return;
            }
            insertElement(node->left, val);
        } else if(node->val < val) {
            if(node->right == nullptr) {
                node->right = new TreeNode(val);
                return;
            }
            insertElement(node->right, val);
        } else return;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            insertElement(root, preorder[i]);
        }

        return root;
    }
};