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
    vector<int> inorder, ans;

    void getInorder(TreeNode* node) {
        if(node == nullptr) return;
        getInorder(node->left);
        inorder.push_back(node->val);
        getInorder(node->right);
    }

    void mergeSortedArray(vector<int>& inorder1, vector<int>& inorder2) {
        int i = 0, j = 0;
        while(i < inorder1.size() and j < inorder2.size()) {
            if(inorder1[i] < inorder2[j]) {
                ans.push_back(inorder1[i++]);
            } else {
                ans.push_back(inorder2[j++]);
            }
        }

        while(i < inorder1.size()) ans.push_back(inorder1[i++]);
        while(j < inorder2.size()) ans.push_back(inorder2[j++]);
        return;
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        getInorder(root1);
        vector<int> inorder1 = inorder;
        inorder.clear();
        getInorder(root2);
        vector<int> inorder2 = inorder;
        mergeSortedArray(inorder1, inorder2);
        return ans;
    }
};