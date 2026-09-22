class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (true) {
            ListNode* groupEnd = prev;
            for (int i = 0; i < k; i++) {
                groupEnd = groupEnd->next;

                if (groupEnd == nullptr)
                    return dummy->next;
            }

            ListNode* groupStart = prev->next;
            ListNode* nextGroup = groupEnd->next;
            ListNode* curr = groupStart;
            ListNode* reversePrev = nextGroup;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = reversePrev;
                reversePrev = curr;
                curr = temp;
            }

            prev->next = groupEnd;
            groupStart->next = nextGroup;
            prev = groupStart;
        }
        return dummy->next;
    }
};