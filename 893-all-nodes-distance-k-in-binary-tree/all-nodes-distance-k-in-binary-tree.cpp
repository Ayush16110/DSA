/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        // step 1 : construct parent map
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // step 2 : start bfs from target and use visited set to safely skip visited nodes
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while(!q.empty() and k) {
            int s = q.size();

            for(int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr and !visited.contains(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if(node->right != nullptr and !visited.contains(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if(parent.count(node) and !visited.contains(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            k--;
        }

        // setp 3 :  build answer
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};