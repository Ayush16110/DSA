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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (ListNode* node : lists) {
            if (node != nullptr)
                pq.push(node);
        }

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            temp->next = curr;
            temp = temp->next;
            if(curr->next != nullptr) pq.push(curr->next);
        }

        return dummy.next;
    }
};