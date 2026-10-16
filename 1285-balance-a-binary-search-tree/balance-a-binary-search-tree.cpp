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
    vector<int> inorder;
    TreeNode* solve(int start, int end) {
        if(start > end) return nullptr;
        int mid = start + (end - start)/2;
        TreeNode* node = new TreeNode(inorder[mid]);
        node->left = solve(start, mid - 1);
        node->right = solve(mid + 1, end);
        return node;
    }
    TreeNode* sortedArrayToBST() {
        int start = 0;
        int end = inorder.size() - 1;
        return solve(start, end);
    }
    void inorderTraversal(TreeNode* node) {
        if(node == nullptr) return;
        inorderTraversal(node->left);
        inorder.push_back(node->val);
        inorderTraversal(node->right);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return sortedArrayToBST();
    }
};