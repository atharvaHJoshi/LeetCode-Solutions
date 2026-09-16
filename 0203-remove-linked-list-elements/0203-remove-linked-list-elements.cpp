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
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to head
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Keep track of the node to delete it from memory later
                ListNode* temp = curr->next;
                // Skip the node with the target value
                curr->next = curr->next->next;
                delete temp; 
            } else {
                // Move forward only if we didn't delete a node
                curr = curr->next;
            }
        }
        
        // The real new head is the next node of our dummy
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node memory
        
        return newHead;
    }
};
