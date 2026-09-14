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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* current = head;
        int length = 0 ; 

        while( current != nullptr )
        {
            length++;
            current = current->next;
        }

        if ( n == length )
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        current = head ;

        int index = length - n - 1 ;
        for( int i = 0 ; i < index ; i++ )
        {
            current = current->next;
        }

        ListNode* nodeToBeDelete = current->next;

        current->next = nodeToBeDelete->next;

        delete nodeToBeDelete;

        return head;
    }
};