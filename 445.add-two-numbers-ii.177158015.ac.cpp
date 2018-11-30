/*
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (47.42%)
 * Total Accepted:    63.1K
 * Total Submissions: 133.1K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	stack<int> st1;
	stack<int> st2;
	stack<int> result;

	while (l1) 
	{
		st1.push(l1->val);
		l1 = l1->next;
	}

	while (l2)
	{
		// cout << l2->val;
        st2.push(l2->val);
		l2 = l2->next;
	}

	int carry = 0;

	while (!st1.empty() && !st2.empty())
	{
		int sum = st1.top() + st2.top() + carry;
		st1.pop();
		st2.pop();
        
        cout << sum % 10 << endl;
		
        result.push(sum%10);
		carry = sum / 10;
	}
    
	while (!st1.empty())
	{
		int sum = st1.top() + carry;
        
		st1.pop();
        
        cout << sum % 10 << endl;
        
		result.push(sum % 10);
		carry = sum / 10;
	}

	while (!st2.empty())
	{
		int sum = st2.top() + carry;

		st2.pop();
        
        // cout << sum % 10 << endl;
        
		result.push(sum % 10);
		carry = sum / 10;
	}
    
	if (carry) result.push(carry);

	ListNode* head = new ListNode(-1);
	ListNode* ans = head;
    
	while (!result.empty())
	{
		ListNode* temp = new ListNode(result.top());
		result.pop();
		head->next = temp;
		head = temp;
	}
	return ans->next;
}
};
