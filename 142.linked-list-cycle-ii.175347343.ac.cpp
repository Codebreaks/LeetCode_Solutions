/*
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (29.94%)
 * Total Accepted:    170.8K
 * Total Submissions: 570.3K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * 
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
ListNode *detectCycle(ListNode *head) {
	if (!head) return NULL;

	ListNode* slow = head;
	ListNode* startLoop = head;
	ListNode* fast = head;

	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) 
		{
			while (startLoop != slow)
			{
				startLoop = startLoop->next;
				slow = slow->next;
			}
			return startLoop;
		}
	}
	return NULL;
}

};
