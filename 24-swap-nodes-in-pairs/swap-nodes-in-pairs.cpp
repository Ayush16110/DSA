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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* prev = dummy->next;

        while(prev != nullptr and prev->next != nullptr) {
            ListNode* curr = prev->next;
            ListNode* next = curr->next;
            curr->next = prev;
            left->next = curr;
            prev->next = next;
            left = prev;
            prev = next;
        }

        return dummy->next;
    }
};