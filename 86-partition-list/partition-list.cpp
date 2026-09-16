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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessStart = new ListNode(0, nullptr);
        ListNode* greatStart = new ListNode(0, nullptr);
        ListNode* less = lessStart;
        ListNode* great = greatStart;
        ListNode* curr = head;

        while(curr != nullptr) {
            if(curr->val >= x) {
                great->next = curr;
                great = great->next;
            } else {
                less->next = curr;
                less = less->next;
            }
            curr = curr->next;
        }

        less->next = greatStart->next;
        great->next = nullptr;

        return lessStart->next;
    }
};