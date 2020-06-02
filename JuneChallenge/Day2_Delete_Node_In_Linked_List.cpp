/*

Question :

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Input:        head = [4,5,1,9], node = 5
Output:       [4,1,9]
Explanation:  You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

*/

//Code:

class Solution {
public:
    void deleteNode(ListNode* node) {
        struct ListNode *temp;
        temp=node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete(temp);
   
    }
};




 
