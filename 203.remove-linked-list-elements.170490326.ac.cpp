/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (34.28%)
 * Total Accepted:    178.8K
 * Total Submissions: 521.5K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
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
ListNode* removeElements(ListNode* head, int val) 
{
	
	if (head)
	{
		ListNode* cur = head;
		ListNode* pre = NULL;
		while (cur != NULL)
		{
			if (cur->val != val)
			{
				pre = cur;
				cur = cur->next;
			}
			else
			{
				ListNode* del = cur;
				cur = cur->next;
				if(pre)
					pre->next = cur;
				
                if(del == head)
                    head = cur;
                
                delete(del);
			}
		}
	
	}
	return head;
}
};
