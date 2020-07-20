/*

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*/

//Code:

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr,*temp=NULL;
        while(head and head->val==val)
        {
            head=head->next;
        }
        curr=head;
        
        while(curr and curr->next)
        {
           if(curr->next->val==val)
           {
               curr->next=curr->next->next;
           }
            else
            {
                curr=curr->next;
            }
        }
        return head;
    }
    
};
