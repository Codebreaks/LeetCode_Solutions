/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (40.92%)
 * Total Accepted:    266K
 * Total Submissions: 649.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
ListNode* deleteDuplicates(ListNode* head) {
	if (head)
	{
		ListNode* cur = head;
		ListNode* pre = NULL;
		while (cur != NULL)
		{
			if (pre && (pre->val == cur->val))
			{
				cur = cur->next;
				pre->next = cur;
                continue;
			}
			pre = cur;
			if (cur) cur = cur->next;
		}
	}
	return head;
}
};
