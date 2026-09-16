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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prevHead = head;
        ListNode* curr = head;
        int n = 0;

        while(curr != nullptr) {
            n++;
            curr = curr->next;
        }

        k = k % n;
        if(k == 0) return head;
        curr = head;

        for(int i = 1; i < n-k; i++) {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;

        curr = newHead;
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = prevHead;

        return newHead;        
    }
};