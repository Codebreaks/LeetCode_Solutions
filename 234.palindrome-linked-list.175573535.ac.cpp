/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (34.26%)
 * Total Accepted:    194.2K
 * Total Submissions: 566.8K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
bool isPalindrome(ListNode* head) {

	if (!head) return true;
	ListNode* slow = head;
	ListNode* fast = head;
	stack<int> holder;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast)//even
	{
		slow = slow->next;
	}

	while (slow)
	{
		holder.push(slow->val);
		slow = slow->next;
	}

	while (!holder.empty())
	{
		if (head->val != holder.top()) return false;
		head = head->next;
		holder.pop();
	}

	return true;

}
};
