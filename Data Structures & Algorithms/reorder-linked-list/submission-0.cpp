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
    void reorderList(ListNode* head) {
        if (!head->next) return;
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow->next is head of new list which we will reverse
        ListNode* prev = NULL, *curr = slow->next, *nex = NULL;
        while (curr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        //1 2 3 4 5 6 = 1 2 3 + 4 5 6 = 1 2 3 + 6 5 4 
        //1 2 3 4 5 6 7 =  1 2 3 4 + 5 6 7 = 1 2 3 4 + 7 6 5
        //prev is head of new reversed list
        //connect 1st of each lists and move forward
        ListNode* ptr1 = head, *ptr2 = prev, *ptr = head;
        slow->next = NULL; //separate both list
        ptr1 = ptr1->next;
        ptr->next = ptr2;
        ptr = ptr->next;
        ptr2 = ptr->next;
        while (ptr1 && ptr2) {
            ptr->next = ptr1;
            ptr = ptr->next;
            ptr1 = ptr1->next;
            ptr->next = ptr2;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        if (ptr1) ptr->next = ptr1;
        return;
    }
};
