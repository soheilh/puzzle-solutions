/*
+------------------------------------------------------------------------------+
| Number       : 23                                                            |
| Title        : Merge k Sorted Lists                                          |
| Link         : https://leetcode.com/problems/merge-k-sorted-lists            |
| Description  : Merge all the linked-lists into one sorted linked-list        |
|                and return it.                                                |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-08-07                                                    |
| Last Modified: 2024-08-07                                                    |
+------------------------------------------------------------------------------+
*/

#include <vector>
#include <climits>
#include <algorithm>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MinHeap {
public:
    MinHeap() {}

    // Insert a new ListNode
    void insert(ListNode* node) {
        heap.push_back(node);
        int i = heap.size() - 1;
        while (i != 0 && heap[parent(i)]->val > heap[i]->val) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Extract the minimum ListNode
    ListNode* extractMin() {
        if (heap.size() <= 0)
            return nullptr;
        if (heap.size() == 1) {
            ListNode* root = heap[0];
            heap.pop_back();
            return root;
        }
        ListNode* root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        minHeapify(0);
        return root;
    }

    ListNode* getMin() {
        if (heap.size() <= 0)
            return nullptr;
        return heap[0];
    }

    bool isEmpty() {
        return heap.size() == 0;
    }

private:
    std::vector<ListNode*> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    void minHeapify(int i) {
        int l = left(i), r = right(i), smallest = i;
        if (l < heap.size() && heap[l]->val < heap[i]->val)
            smallest = l;
        if (r < heap.size() && heap[r]->val < heap[smallest]->val)
            smallest = r;
        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        MinHeap minHeap;

        // Push the head of each list into the min-heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.insert(list);
            }
        }

        // Dummy node to help with the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Process the heap
        while (!minHeap.isEmpty()) {
            // Get the smallest node
            ListNode* smallest = minHeap.extractMin();

            // Add it to the merged list
            tail->next = smallest;
            tail = tail->next;

            // Push the next node from the same list into the heap
            if (smallest->next != nullptr) {
                minHeap.insert(smallest->next);
            }
        }

        // The head of the merged list
        ListNode* mergedHead = dummy->next;
        delete dummy;
        return mergedHead;
    }
};
