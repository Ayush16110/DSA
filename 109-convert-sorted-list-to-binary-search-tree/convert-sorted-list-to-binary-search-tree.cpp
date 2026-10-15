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
    TreeNode* solve(ListNode* list, int start, int end) {
        if(start > end) return nullptr;
        int mid = start + (end - start)/2;
        ListNode* curr = list;
        int count = 0;
        while(count < mid and curr != nullptr and curr->next != nullptr) {
            curr = curr->next;
            count++;
        }
        TreeNode* node = new TreeNode(curr->val);
        node->left = solve(list, start, mid - 1);
        node->right = solve(list, mid + 1, end);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        int start = 0;
        int end = 0;
        ListNode* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
            end++;
        }
        return solve(head, start, end);
    }
};