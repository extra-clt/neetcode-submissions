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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        int len = 0;
        ListNode* ptr = head;
        while (ptr) {
            len++;
            ptr = ptr->next;
        }
        int front = len - n;
        cout << front;
        if (front == 0) return head->next;
        ListNode* ptr1 = head;
        while (front > 1) {
            ptr1 = ptr1->next;
            front--;
        }
        ptr= ptr1->next->next;
        ptr1->next = ptr;
        return head;
    }
};
