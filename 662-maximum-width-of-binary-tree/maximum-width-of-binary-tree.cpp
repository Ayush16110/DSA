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
        long long ans = 1;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()) {
            int s = q.size();
            long long base = q.front().second;
            
            for(int i = 0; i < s; i++) {
                if(i == s-1) ans = max(ans, q.front().second - base + 1);
                TreeNode* node = q.front().first;
                long long index = q.front().second - base;
                q.pop();

                if(node->left) q.push({node->left, index * 2});
                if(node->right) q.push({node->right, index * 2 + 1});
            }
        }

        return ans;
    }
};