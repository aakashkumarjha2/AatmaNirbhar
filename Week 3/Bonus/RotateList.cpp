//https://leetcode.com/problems/rotate-list/
/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<ListNode*>v;
        if(head==NULL)
            return head;
        ListNode*temp = head;
        int count= 0;
        while(temp!=NULL)
        {
            v.push_back(temp);
            temp=temp->next;
            count++;
        }
        if(count==1 || k==count)
            return head;
        k = k%count;
        if(k==0)
            return head;
        int index = count-k-1;
        v[count-1]->next = head;
        head = v[index+1];
        v[index]->next = NULL;
        return head;
        
    }
};
