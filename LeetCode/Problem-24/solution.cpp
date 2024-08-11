/*
+--------------------------------------------------------------------------+
| Problem Number : 24                                                      |
| Title          : Swap Nodes in Pairs                                     |
| Link           : https://leetcode.com/problems/swap-nodes-in-pairs       |
| Description    : Given a linked list, swap every two adjacent nodes and  |
|                  return its head.                                        |
+--------------------------------------------------------------------------+
| Author         : Soheil Hasani                                           |
| Date Created   : 2024-08-10                                              |
| Last Updated   : 2024-08-11                                              |
+--------------------------------------------------------------------------+
*/

/*
 * Time Complexity: O(n) - Each node in the linked list is visited exactly once.
 * Space Complexity: O(1) - The space used is constant, as only a few pointers are used for swapping.
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If there are fewer than 2 nodes, return the list as it is.
        if (!head || !head->next) {
            return head;
        }

        // Initialize pointers
        ListNode* newHead = head->next;
        ListNode* prev = nullptr;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Swap the nodes
            first->next = second->next;
            second->next = first;

            // Connect the previous pair to the current swapped pair
            if (prev) {
                prev->next = second;
            }

            // Move the pointers forward
            prev = first;
            head = first->next;
        }

        return newHead;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    // Instantiate the Solution class and call swapPairs
    Solution solution;
    ListNode* result = solution.swapPairs(node1);

    // Print the modified linked list
    while (result) {
        std::cout << result->val << ' ';
        result = result->next;
    }
    std::cout << std::endl;

    // Clean up dynamically allocated memory
    while (node1) {
        ListNode* temp = node1;
        node1 = node1->next;
        delete temp;
    }

    return 0;
}

