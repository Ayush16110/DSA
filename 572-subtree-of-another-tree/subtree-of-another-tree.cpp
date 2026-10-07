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
    bool isSame(TreeNode* first, TreeNode* second) {
        if(first == nullptr and second == nullptr) return true;
        if((first == nullptr and second != nullptr) || (first != nullptr and second == nullptr) || (first->val != second->val)) return false;
        return (isSame(first->left, second->left) && isSame(first->right, second->right));
    }
        
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) {
            if(subRoot == nullptr) return true;
            return false;
        }

        if(subRoot == nullptr) return true;

        if(root->val == subRoot->val) {
            if(isSame(root, subRoot)) return true;
        }

        if(isSubtree(root->left, subRoot)) return true;
        if(isSubtree(root->right, subRoot)) return true;
        return false;        
    }
};