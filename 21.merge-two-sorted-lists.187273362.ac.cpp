/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (43.30%)
 * Total Accepted:    415.6K
 * Total Submissions: 959.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    

ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) 
{
	if (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			 l1->next = mergeTwoLists(l1->next, l2);
            return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
            return l2;
		}
	}
    
    return (l1 == NULL) ? l2 : l1;
}
    
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
 {
	 ListNode* ans = new ListNode(-1);
	 ListNode* ansholder = ans;

	 while (l1 && l2)
	 {
		 if (l1->val < l2->val)
		 {
			 ans->next = l1;
			 l1 = l1->next;
			 
		 }
		 else
		 {
			 ans->next = l2;
			 l2 = l2->next;
		 }
		 ans = ans->next;
	 }

	 if (l1)
		 ans->next = l1;
	 else
		 ans->next = l2;

	 return ansholder->next;
 }
    
    
    
};
