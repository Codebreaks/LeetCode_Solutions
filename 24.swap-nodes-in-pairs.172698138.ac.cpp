/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (40.97%)
 * Total Accepted:    242.6K
 * Total Submissions: 592.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Note:
 * 
 * 
 * Your algorithm should use only constant extra space.
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
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
ListNode* swapPairs(ListNode* head) {

	ListNode* dummy = new ListNode(-1);

	if (head)
	{
		ListNode* pre = head;
		ListNode* cur = head->next;
        if(!cur) return head;
		dummy->next = cur;
		ListNode* start = dummy;
		ListNode* next = NULL;

		while (pre && cur)
		{
			next = cur->next;
			pre->next = next;
			cur->next = pre;

			dummy->next = cur;
			dummy = pre;

			pre = next;
            
			if (next)
				cur = next->next;
		}
		return start->next;

	}
	return head;

}
};
