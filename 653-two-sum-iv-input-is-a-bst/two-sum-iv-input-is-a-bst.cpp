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
    unordered_map<int, TreeNode*> m;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        if(findTarget(root->left, k)) return true;
        if(m.find(k - root->val) != m.end()) return true;
        m[root->val] = root;
        if(findTarget(root->right, k)) return true;
        return false;
    }
};