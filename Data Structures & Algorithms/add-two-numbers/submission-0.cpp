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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2;
        int num = 0, carry = 0;
        while (ptr1 && ptr2) {
            num = ptr1->val + ptr2->val + carry;
            carry = 0;
            if (num > 9) {
                carry = 1;
                num -= 10;
            }
            ptr1->val = num;
            ptr2->val = num;
            if (!ptr1->next) break;
            if (!ptr2->next) break;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (!ptr1->next && !ptr2->next && carry == 1) {
            ListNode* newNode = new ListNode(1);
            ptr1->next = newNode;
            return l1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        while (ptr1) {
            num = ptr1->val + carry;
            carry = 0;
            if (num > 9) {
                carry = 1;
                num -= 10;
            }
            ptr1->val = num;
            if (!ptr1->next) {
                if (carry == 1) {
                    ListNode* newNode = new ListNode(1);
                    ptr1->next = newNode;
                }
                return l1;
            }
            ptr1 = ptr1->next;
        }
        while (ptr2) {
            num = ptr2->val + carry;
            carry = 0;
            if (num > 9) {
                carry = 1;
                num -= 10;
            }
            ptr2->val = num;
            if (!ptr2->next) {
                if (carry == 1) {
                    ListNode* newNode = new ListNode(1);
                    ptr2->next = newNode;
                }
                return l2;
            }
            ptr2 = ptr2->next;
        }
        return l2;
    }
};
