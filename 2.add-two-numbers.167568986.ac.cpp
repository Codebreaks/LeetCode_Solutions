/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.19%)
 * Total Accepted:    603.6K
 * Total Submissions: 2.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* result = getNewNode();
		ListNode* returnNode = result;
		int carry = 0;
		bool firstnode = true;

		while (l1 != NULL && l2 != NULL)
		{
			if (firstnode)
			{
				result->val = (l1->val + l2->val + carry) % 10;
				carry = (l1->val + l2->val + carry) / 10;
				firstnode = false;
			}
			else
			{
				ListNode* tempNode = getNewNode();
				tempNode->val = (l1->val + l2->val + carry) % 10;
				carry = (l1->val + l2->val + carry) / 10;
				result->next = tempNode;
				result = tempNode;
			}
			l1 = l1->next;
			l2 = l2->next;

		}

		if (l1 == NULL)
		{
			while (l2 != NULL)
			{
				ListNode* tempNode = getNewNode();
				tempNode->val = (l2->val + carry) % 10;
				carry = (l2->val + carry) / 10;
				result->next = tempNode;
				result = tempNode;
				l2 = l2->next;
			}
		}

		if (l2 == NULL)
		{
			while (l1 != NULL)
			{
				ListNode* tempNode = getNewNode();
				tempNode->val = (l1->val + carry) % 10;
				carry = (l1->val + carry) / 10;
				result->next = tempNode;
				result = tempNode;
				l1 = l1->next;
			}
		}

		if (carry != 0)
		{
			ListNode* tempNode = getNewNode();
			tempNode->val = carry;
			result->next = tempNode;
			result = tempNode;
		}

		return returnNode;

	}

	ListNode* getNewNode()
	{
		return new ListNode(0);
	}
};
