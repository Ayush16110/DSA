/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<TreeNode*>& inorder, int start, int end) {
        if(start > end) return nullptr;
        int mid = start + (end - start)/2;
        TreeNode* node = inorder[mid];
        node->left = solve(inorder, start, mid - 1);
        node->right = solve(inorder, mid + 1, end);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        vector<TreeNode*> inorder;
        ListNode* curr = head;
        while(curr != nullptr) {
            TreeNode* node = new TreeNode(curr->val);
            inorder.push_back(node);
            curr = curr->next;
        }

        int start = 0;
        int end = inorder.size() - 1;
        TreeNode* root = solve(inorder, start, end);
        return root;
    }
};