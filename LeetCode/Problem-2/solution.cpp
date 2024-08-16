/*
+------------------------------------------------------------------------------+
| Number       : 2                                                             |
| Title        : Add Two Numbers                                               |
| Link         : https://leetcode.com/problems/add-two-numbers                 |
| Description  : Add two numbers represented by linked lists in reverse order  |
|                and return the sum as a linked list.                          |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-08-07                                                    |
| Last Modified: 2024-08-16                                                    |
+------------------------------------------------------------------------------+
*/

/*
 - Time Complexity: O(max(m, n)) - The algorithm iterates through both linked lists simultaneously, running for the length of the longer list.
 - Space Complexity: O(max(m, n)) - A new linked list is created to store the result, with a length of up to max(m, n) + 1.
*/

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
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* result = head;

        while(l1 != nullptr || l2 != nullptr){
            int val1 = (l1 == nullptr) ? 0 : l1->val;
            int val2 = (l2 == nullptr) ? 0 : l2->val;
            int sum = val1 + val2 + carry;
            carry = 0;
            if(sum > 9){
                sum = sum - 10;
                carry = 1;
            }
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            result->next = new ListNode(sum);
            result = result->next;
        }
        if (carry == 1) {
            result->next = new ListNode(carry);
        }

        return head->next;
    }
};