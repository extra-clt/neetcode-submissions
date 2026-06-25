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
        if (!node) return NULL;
        stack<Node*> s;
        unordered_map<Node*,Node*> um;
        Node* newHead = new Node(node->val);
        um[node] = newHead;
        s.push(node);
        while (!s.empty()) {
            Node* n = s.top();
            s.pop();
            for (auto i : n->neighbors) {
                if (!um.count(i)) {
                    Node* newNode = new Node(i->val);
                    um[i] = newNode;
                    s.push(i);
                }
                um[i]->neighbors.push_back(um[n]);
            }
        }
        return newHead;
    }
};
