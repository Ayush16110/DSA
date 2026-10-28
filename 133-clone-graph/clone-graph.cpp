/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        Node* copy = new Node(node->val);
        queue<Node*> q;
        unordered_map<Node*, Node*> m;
        q.push(node);
        m[node] = copy;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            Node* currCopy = m[curr];

            for (auto nbr : curr->neighbors) {
                if (m.find(nbr) != m.end()) {
                    currCopy->neighbors.push_back(m[nbr]);
                    continue;
                }
                Node* copyNbr = new Node(nbr->val);
                m[nbr] = copyNbr;
                q.push(nbr);
                currCopy->neighbors.push_back(copyNbr);
            }
        }

        return copy;
    }
};