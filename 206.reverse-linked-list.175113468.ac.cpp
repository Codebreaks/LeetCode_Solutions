/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (49.60%)
 * Total Accepted:    421.9K
 * Total Submissions: 850.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
 */
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
void reverseList(ListNode* head, ListNode* pre, ListNode** newhd)
{
	if (head)
	{
		
		
		if (head->next != NULL)
		{
			reverseList(head->next, head, newhd);
		}

		if (head->next == NULL)
			*newhd = head;

		head->next = pre;
	
	}
}


ListNode* reverseList(ListNode* head) 
{
	ListNode* newHead = NULL;
	reverseList(head, NULL, &newHead);
	return newHead;
}
    
};
