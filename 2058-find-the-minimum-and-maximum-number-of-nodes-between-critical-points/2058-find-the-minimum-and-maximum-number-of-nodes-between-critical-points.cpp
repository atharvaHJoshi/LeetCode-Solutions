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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};

        int firstIdx = -1, lastIdx = -1, minDim = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;

        while (curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                if (firstIdx == -1) {
                    firstIdx = idx;
                } else {
                    minDim = min(minDim, idx - lastIdx);
                }
                lastIdx = idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (firstIdx == lastIdx) return {-1, -1};
        return {minDim, lastIdx - firstIdx};
    }
};

