/*

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/

//Code:

class Solution {
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        while( head != NULL ){
        ++len; head = head->next;
        }
        return len;
    }

    ListNode * reorderList(ListNode *head, int len)
    {
        if(len == 0)
            return NULL;
        if( len == 1 )
            return head;
        if( len == 2 )
            return head->next;
        ListNode * tail = reorderList(head->next, len-2);
        ListNode * tmp = tail->next;
        tail->next = tail->next->next;
        tmp->next = head->next;
        head->next = tmp;
        return tail;
    }
    void reorderList(ListNode* head) {
     ListNode  * tail = NULL;
     tail = reorderList(head, getLength(head));   
    }
};
