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
    ListNode* rec(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode* newHead = rec(head->next);
        head->next->next = head;   //1-2-3-4_
        //                               ^__|
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        return rec(head);
    }
};
