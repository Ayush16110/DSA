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
    void pushLeft(TreeNode* node, stack<TreeNode*>& s) {
        while (node != nullptr) {
            s.push(node);
            node = node->left;
        }
    }

    int next(stack<TreeNode*>& s) {
        TreeNode* temp = s.top();
        s.pop();
        pushLeft(temp->right, s);
        return temp->val;
    }

    bool hasNext(stack<TreeNode*>& s) { return !s.empty(); }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        pushLeft(root1, s1);
        pushLeft(root2, s2);
        vector<int> ans;

        while (hasNext(s1) && hasNext(s2)) {
            if (s1.top()->val < s2.top()->val) {
                ans.push_back(next(s1));
            } else {
                ans.push_back(next(s2));
            }
        }

        while (hasNext(s1)) {
            ans.push_back(next(s1));
        }

        while (hasNext(s2)) {
            ans.push_back(next(s2));
        }

        return ans;
    }
};