//https://leetcode.com/problems/reverse-nodes-in-k-group/
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head,*prev=NULL,*nex=NULL;
        int count=0;
        while(count<k && cur!=NULL)
        {
            cur=cur->next;
            count++;
        }
        if(count<k)
            return head;
        cur=head;
        count=0;
        while(cur!=NULL && count<k)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
            count++;
        }
        if(nex!=NULL)
            head->next=reverseKGroup(nex,k);
        return prev;
    }
};