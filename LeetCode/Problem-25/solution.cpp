/*
+--------------------------------------------------------------------------+
| Problem Number : 25                                                      |
| Title          : Reverse Nodes in k-Group                                |
| Link           : https://leetcode.com/problems/reverse-nodes-in-k-group  |
| Description    : Given a linked list, reverse the nodes of the list k    |
|                  at a time and return the modified list.                 |
+--------------------------------------------------------------------------+
| Author         : Soheil Hasani                                           |
| Date Created   : 2024-08-11                                              |
| Last Updated   : 2024-08-11                                              |
+--------------------------------------------------------------------------+
*/

/*
 * Time Complexity: O(n) - Each node in the linked list is visited exactly once.
 * Space Complexity: O(n/k) - Due to the recursion stack depth.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes left in the list
        ListNode* current = head;
        for (int i = 0; i < k; ++i) {
            if (current == nullptr) return head; // Less than k nodes, return head as is
            current = current->next;
        }

        // Step 2: Reverse k nodes
        ListNode* previous = nullptr;
        ListNode* currentNode = head;
        ListNode* nextNode = nullptr;
        for (int i = 0; i < k; ++i) {
            nextNode = currentNode->next;
            currentNode->next = previous;
            previous = currentNode;
            currentNode = nextNode;
        }

        // Step 3: Recursively process the next groups
        head->next = reverseKGroup(currentNode, k);

        // Return the new head of the reversed k-group
        return previous;
    }
};

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 4
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    // Instantiate the Solution class and call reverseKGroup
    Solution solution;
    int k = 2;
    ListNode* result = solution.reverseKGroup(node1, k);

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

