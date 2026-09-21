/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while(curr != nullptr) {
            if(curr->child != nullptr) {
                if(curr->next == nullptr) {
                    curr->next = curr->child;
                    curr->child->prev = curr;
                    curr->child = nullptr;
                } else {
                    Node* next = curr->next;
                    curr->next = curr->child;
                    curr->next->prev = curr;
                    curr->child = nullptr;
                    Node* temp = curr;
                    while(temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = next;
                    next->prev = temp;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};