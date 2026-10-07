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
    vector<vector<int>> ans;
    vector<int> current;
    void solve(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return;
        if (root->left == nullptr and root->right == nullptr) {
            if (targetSum == root->val) {
                current.push_back(root->val);
                ans.push_back(current);
                current.pop_back();
            }
            return;
        }

        current.push_back(root->val);
        solve(root->left, targetSum - root->val);
        solve(root->right, targetSum - root->val);
        current.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        return ans;
    }
};