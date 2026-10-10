/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        Node* curr = root;
        Node* nextLevelStart = nullptr;
        Node* prev = nullptr;

        while(curr != nullptr) {
            if(curr->left) {
                if(nextLevelStart == nullptr) {
                    nextLevelStart = curr->left;
                    prev = curr->left;
                } else {
                    prev->next = curr->left;
                    prev = curr->left;
                }
            }

            if(curr->right) {
                if(nextLevelStart == nullptr) {
                    nextLevelStart = curr->right;
                    prev = curr->right;
                } else {
                    prev->next = curr->right;
                    prev = curr->right;
                }
            }

            curr = curr->next;

            if(curr == nullptr) {
                curr = nextLevelStart;
                nextLevelStart = nullptr;
                prev == nullptr;
            }
        }

        return root;
    }
};