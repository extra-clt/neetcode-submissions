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
        unordered_map<Node*,Node*> um;
        Node* ptr = head;
        while (ptr) {
            Node* newNode = new Node(ptr->val);
            um[ptr] = newNode;
            ptr = ptr->next;
        }
        ptr = head;
        Node* newHead = um[head];
        Node* ptr1 = um[head];
        while (ptr) {
            ptr1->next = um[ptr->next];
            ptr1->random = um[ptr->random];
            ptr = ptr->next;
            ptr1 = ptr1->next;
        } 
        return newHead;
    }
};
