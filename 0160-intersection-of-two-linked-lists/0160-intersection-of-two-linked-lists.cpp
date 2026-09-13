/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> my_set;

        ListNode* currentA = headA;
        ListNode* currentB = headB;

        while( currentA != nullptr ) //&& currentA->next != nullptr )
        {
            my_set.insert( currentA );

            currentA= currentA->next;
        }   

        while( currentB != nullptr ) //&& currentB->next != nullptr )
        {
            if (my_set.contains( currentB) )
            {
                return currentB;
            }
            currentB = currentB->next;
        }

        return nullptr;
    }
};