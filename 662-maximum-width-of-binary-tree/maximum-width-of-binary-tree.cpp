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
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans = 0;

        while(!q.empty()) {
            int sz = q.size();
            long long base = q.front().second;

            for(int i = 0; i < sz; i++) {
                if(i == sz - 1) ans = max(ans, q.front().second - base + 1);
                TreeNode* node = q.front().first;
                long long index = q.front().second - base;
                q.pop();
                if(node->left) q.push({node->left, index * 2});
                if(node->right) q.push({node->right, (index * 2) + 1});
            }
        }

        return ans;
    }
};