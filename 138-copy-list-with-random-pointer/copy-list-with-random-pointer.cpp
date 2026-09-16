/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* original = head;

        unordered_map<Node*, Node*> m;

        while(original != nullptr) {
            m[original] = new Node(original->val);
            original = original->next;
        }

        original = head;

        while(original != nullptr) {
            Node* copy = m[original];
            copy->next = (original->next != nullptr) ? m[original->next] : nullptr;
            copy->random = (original->random != nullptr) ? m[original->random] : nullptr;
            original = original->next;
        }

        return m[head];        
    }
};