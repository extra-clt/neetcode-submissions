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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode *ptr1 = list1, *ptr2 = list2, *head = NULL;
        ListNode* ptr = NULL;
        if (ptr2->val < ptr1->val) {
            head = ptr2;
            ptr = ptr2;
            ptr2 = ptr2->next;
        }
        else {
            head = ptr1;
            ptr = ptr1;
            ptr1 = ptr1->next;
        }
        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        if (ptr1) ptr->next = ptr1;
        if (ptr2) ptr->next = ptr2;
        return head;
    }
};
