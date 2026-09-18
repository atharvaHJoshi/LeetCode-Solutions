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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if ( head == nullptr || left == right )
        {
            return head;
        }

        ListNode dummy(0);
        
        dummy.next = head;

        ListNode* before = &dummy  ;

        for ( int i = 1 ; i < left ; i++ )
        {
            before = before->next;
        }

        ListNode* reverseStartNode = before->next;
        ListNode* current = reverseStartNode ;
        ListNode* prev = nullptr;

        for( int i = left ; i <= right ; i++ )
        {
            ListNode* next = current->next;
            current->next = prev ;
            prev = current ;
            current = next;
        } 


        before->next = prev;
        reverseStartNode->next = current;

        return dummy.next;
    }
};